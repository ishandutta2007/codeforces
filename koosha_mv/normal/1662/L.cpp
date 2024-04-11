#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;

int n,spd,a[N],t[N],A[N],B[N],dp[N],pos[N],fenwik[N];

vector<int> op;

void add(int x, int val){ op.pb(x); for(x+=3;x<N;x+=x&-x) maxm(fenwik[x],val); }
int get(int x) { int res=-N; for (x+=3;x>0;x-=x&-x) maxm(res,fenwik[x]); return res; }
void clear(){
	for(auto x : op){
		for(x+=3;x<N;x+=x&-x) fenwik[x]=-N;
	}	
	op.clear();
}

void solve(int l=0,int r=n){
	if(l>=r) return ;
	int mid=(l+r)>>1;
	solve(l,mid);
	vector<int> vec;
	f(i,l,r + 1) vec.pb(i);
	
	sort(all(vec),[&](int u,int v){ return mp(A[u],u)<=mp(A[v],v); });
	f(i,0,vec.size()){
		int x=vec[i];
		if(x<=mid) add(pos[x],dp[x]);
		else{
			maxm(dp[x],get(pos[x])+1);
		}	
	}
	clear();
	
	sort(all(vec),[&](int u,int v){ return mp(B[u],u)<=mp(B[v],v); });
	f(i,0,vec.size()){
		int x=vec[i];
		if(x<=mid) add(n + 10 - pos[x],dp[x]);
		else{
			maxm(dp[x],get(n + 10 -pos[x])+1);
		}	
	}
	clear();
	
	solve(mid + 1,r);
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(fenwik,fenwik+N,-N);
	fill(dp+1,dp+N,-N);
	vector<int> vec;
	cin>>n>>spd;
	f(i,1,n+1) cin>>t[i],t[i]*=spd;
	vec.pb(0);
	f(i,1,n+1){
		cin>>a[i];
		vec.pb(a[i]);
	}
	sort(all(vec));
	f(i,0,n+1) pos[i]=lower_bound(all(vec),a[i])-vec.begin()+1;
	f(i,1,n+1){
		A[i]=t[i]-a[i];
		B[i]=a[i]+t[i];
		/*A[i] = -A[i];
		B[i] = -B[i];*/
	}
	solve();
	int ans=0;
	f(i,1,n+1) maxm(ans,dp[i]);
	cout<<ans;
}
/*
3 1
5 7 8
3 3 -2
*/