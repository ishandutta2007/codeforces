#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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
#define pii pair<int,int>

const int N=1e6+99;

int n,t,a[N],R[N],fenwik[N];
vector<int> vec;
vector<pii> upd[N];

void add(int x, int val){ for(x++;x<N;x+=x&-x){ maxm(fenwik[x],val); vec.pb(x); } }
int get(int x) { int res=0; for (x++;x>0;x-=x&-x) maxm(res,fenwik[x]); return res; }

void Main(){
	vector<pair<int,int>> p;
	int ans=0;
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f_(i,n,1){
		R[i]=i+1;
		while(R[i]<=n && a[R[i]]<a[i]) R[i]=R[R[i]];
	}
	upd[1].pb({0,1});
	f(i,1,n+1){
		int x=a[i];
		int res=get(x)+1;
		add(x,res);
		maxm(ans,res);
		upd[R[i]].pb({x,res+1});
		for(auto x : upd[i]) add(x.F,x.S);
	}	
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		for(auto x : vec) fenwik[x]=0;
		vec.clear();
		f(i,0,n+10) upd[i].clear();
	}
}