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

const int N=2e5+99,M=62,P=16,T=30;
mt19937 rng(time(nullptr));

int n,m,p,dp[(1<<P)],inv[N],mark[N];
ll ans,res,a[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(NULL));
	cin>>n>>m>>p;
	uniform_int_distribution<int> rnd(0,n-1);
	f(i,0,n) f(j,0,m){
		char c;
		cin>>c;
		a[i]^=(1ll<<j)*(c-'0');
	}
	f(t,0,T){
		int id=rnd(rng),cnt=0;
		f(i,0,(1<<p)) dp[i]=0;
		f(i,0,m) if(bit(a[id],i)) inv[cnt]=i,mark[i]=cnt++;
		f(i,0,n){
			int task=0;
			f(j,0,m){
				if(bit(a[id],j) && bit(a[i],j)){
					task^=(1<<mark[j]);
				}
			}
			dp[task]++;
		}
		f(i,0,p){
			f(mask,0,(1<<p)){
				if(bit(mask,i)){
					dp[mask^(1<<i)]+=dp[mask];
				}
			}
		}
		int mx=0;
		f(mask,0,(1<<p)){
			if(2*dp[mask]<n) continue ;
			maxm(mx,(ll)nb(mask));
		}
		if(mx<=res) continue ;
		res=mx,ans=0;
		f(mask,0,(1<<p)){
			if(2*dp[mask]>=n && nb(mask)==mx){
				f(i,0,p){
					if(bit(mask,i)){
						ans^=(1ll<<inv[i]);
					}
				}
				break;
			}
		}
	}
	f(i,0,m) cout<<bit(ans,i);
}