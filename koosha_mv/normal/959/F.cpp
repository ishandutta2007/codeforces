#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=(1<<20),mod=1e9+7;

int n,t,q,cnt,a[N],res[N],mark[N];
vector<int> v;
vector<pair<int,int> > vq[N];

int main(){
	cin>>n>>q;
	f(i,1,n+1) cin>>a[i];
	f(i,0,q){
		int u,v;
		cin>>u>>v;
		vq[u].pb(mp(v,i));
	}	
	int ans=1;
	v.pb(0);
	mark[0]=1;
	f(i,1,n+1){
		if(mark[a[i]]) ans=2ll*ans%mod;
		else{
			int sz=v.size();
			f(j,0,sz){
				v.pb(v[j]^a[i]);
				mark[v[j]^a[i]]=1;
			}
		}
		f(j,0,vq[i].size()){
			if(mark[vq[i][j].F]){
				res[vq[i][j].S]=ans;
			}
		}
	}
	f(i,0,q){
		cout<<res[i]<<" ";
	}
}