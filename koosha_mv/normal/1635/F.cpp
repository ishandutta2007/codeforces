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
#define int ll

const int N=3e5+99,inf=4e18;

int n,q,a[N],w[N],L[N],R[N],ans[N],fenwik[N];
vector<int> vec[N];
vector<pair<int,int>> Q[N];

void upd(int x, int val){ for(x++;x;x-=x&-x) minm(fenwik[x],val); }
int get(int x) { int res=inf; for (x++;x<N;x+=x&-x) minm(res,fenwik[x]); return res; }

void build(){
	f(i,1,n+1){
		L[i]=i-1;
		while(w[L[i]]>w[i]) L[i]=L[L[i]];
		if(L[i]) vec[i].pb(L[i]);	
	}
	f_(i,n,1){
		R[i]=i+1;
		while(w[R[i]]>w[i]) R[i]=R[R[i]];
		if(R[i]<=n) vec[R[i]].pb(i);
	}
}
void solve(){
	f(i,1,n+1){
		for(auto x : vec[i]){
			//eror((a[i]-a[x])*(w[i]+w[x]));
			upd(x,(a[i]-a[x])*(w[i]+w[x]));
		}
		for(auto p : Q[i]){
			ans[p.S]=get(p.F);
		}
	}	
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	fill(fenwik,fenwik+N,inf);
	cin>>n>>q;
	f(i,1,n+1) cin>>a[i]>>w[i];
	f(i,0,q){
		int l,r;
		cin>>l>>r;
		Q[r].pb({l,i});
	}
	build();
	solve();
	f(i,0,q) cout<<ans[i]<<" ";
}