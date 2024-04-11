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

const int N=3e5+99,mod=998244353;

int n,t,ans,a[N],P2[N],P3[N];
vector<int> ad[N],dl[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	P2[0]=P3[0]=1;
	f(i,1,N){
		P2[i]=P2[i-1]*2ll%mod;
		P3[i]=P3[i-1]*3ll%mod;
	}
	cin>>n;
	f(i,0,n){
		int l,r;
		cin>>l>>r;
		ad[l].pb(i);
		dl[r].pb(i);
	}
	set<int> s;
	f(i,0,N){
		for(auto x : ad[i]) s.insert(x);
		if(s.size()){
			int x=*s.rbegin(),res;
			if(x==0) res=1;
			else{
				res=2ll*P3[x-1]%mod;
			}
			Add(ans,1ll*res*P2[n-1-x]%mod);
		}
		for(auto x : dl[i]) s.erase(x);
	}
	cout<<ans;
}