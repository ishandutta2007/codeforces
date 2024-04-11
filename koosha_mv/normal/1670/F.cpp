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

const int N=1005,lg=63,mod=1e9+7;

int n,l,r,k,a[N],C[N][N],dp[lg][2*N][2][2];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,0,N){
		C[0][i]=1;
		f(j,1,i+1) C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
	}
	cin>>n>>l>>r>>k; l--;
	dp[0][0][0][0]=1;
	f(i,0,lg-1){
		f(j,0,2*N){
			f(sl,0,2){
				f(sr,0,2){
					//cout<<i<<" "<<j<<" "<<sl<<" "<<sr<<" -> "<<dp[i][j][sl][sr]<<endl;
					for(int t=bit(k,i);t<=n;t+=2){
						int tl=sl,tr=sr,b=(t+j)&1;
						if(bit(l,i)<b) tl=1;
						if(b<bit(l,i)) tl=0;
						if(bit(r,i)<b) tr=1;
						if(b<bit(r,i)) tr=0;
						Add(dp[i+1][(j+t)/2][tl][tr],1ll*dp[i][j][sl][sr]*C[t][n]%mod);
					}
				}
			}
		}
	}
	cout<<dp[lg-1][0][1][0];
}