#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

const int N=2005,K=62,mod=1e9+7;

ll n,k,a[N],pd[2][5],ans[K];
set<ll> s;
map<ll,ll> dp[5],mark,mv;
vector<ll> v;

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

ll G(ll x){
	f_(i,K,0)
		if((1ll<<i)&x)
			return i;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f(i,1,K) ans[i]=pow(4,(1ll<<i)-2,mod)*2ll%mod;
	cin>>k>>n;
	f(i,0,n){
		string t;
		ll x;
		cin>>x>>t;
		int type;
		if(t[0]=='y' || t[0]=='w') type=1;
		if(t[0]=='b' || t[0]=='g') type=2;
		if(t[0]=='r' || t[0]=='o') type=3;
		mark[x]=type;
		while(x){
			s.insert(x);
			mv[x]=1;
			x/=2;
		}
		
	}
	while(s.size()){
		v.pb(*s.rbegin());
		s.erase(*s.rbegin());
	}
	f(i,0,v.size()){
		ll u=v[i],x=v[i]*2,y=v[i]*2+1,e=G(v[i]);
		if(e==k-1){
			dp[mark[u]][u]=1;
		}
		else{
			f(l,0,2){
				if(!mv[x]) f(j,1,4) pd[l][j]=ans[k-e-1];
				else f(j,1,4){ pd[l][j]=dp[j][x]; }
				swap(x,y);
				//f(j,1,4) eror(pd[l][j]);
			}
			f(s1,1,4)
				f(s2,1,4)
					f(s3,1,4)
						if(s1!=s2 && s1!=s3 && (mark[u]==0 || mark[u]==s1)){
							Add(dp[s1][u],(1ll+(mark[u]==0))*pd[0][s2]*pd[1][s3]%mod);
							//cout<<s1<<" "<<u<<" "<<dp[s1][u]<<endl;
						}
		}
		//eror(u);
		//cout<<dp[1][u]<<" "<<dp[2][u]<<" "<<dp[3][u]<<endl;
	}
	cout<<(1ll*dp[1][1]+dp[2][1]+dp[3][1])%mod;
}