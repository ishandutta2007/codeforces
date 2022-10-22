#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=3e5+99,base=10000103,mod=1e9+9;
 
int n,t,inv,a[N],b[N];
ll ans;
map<int,int> mark[N];
 
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
 
main(){
	b[0]=1;
	f(i,1,N){
		b[i]=1ll*b[i-1]*base%mod;
	}
	cin>>t;
	while(t--){
		vector<int> v;
		int hash=0;
		cin>>n;
		f(i,1,n+1) cin>>a[i];
		mark[0][0]++;
		f(i,1,n+1){
			if(v.size() && a[i]==v.back()){
				v.pop_back();
				Add(hash,mod-(1ll*b[v.size()]*a[i]%mod));
			}
			else{
				Add(hash,1ll*b[v.size()]*a[i]%mod);
				v.pb(a[i]);
			}
			ans+=mark[v.size()][hash];
			mark[v.size()][hash]++;
		}
		cout<<ans<<endl;
		
		ans=0;
		f(i,0,n+10) mark[i].clear();
	}
}