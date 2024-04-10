#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=110;
int n,a[N],b[N],dp[N][N*N],pd[N][N*N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) scanf("%d",b+i);
	dp[0][0]=0;
	int sa=0,sb=0;
	rep(i,0,n) {
		rep(j,0,i+1) rep(k,0,sb+1) pd[j][k]=dp[j][k];
		rep(j,0,i+1) rep(k,0,sb+1+b[i]) dp[j][k]=-(1<<20);
		rep(j,0,i+1) rep(k,0,sb+1) {
			dp[j][k]=max(dp[j][k],pd[j][k]);
			dp[j+1][k+b[i]]=max(dp[j+1][k+b[i]],pd[j][k]+a[i]);
		}
		sa+=a[i],sb+=b[i];
	}
	int ret=0;
	rep(j,0,n+1) {
		rep(k,sa,sb+1) if (dp[j][k]>=0) {
			ret=max(ret,dp[j][k]);
		}
		if (ret>0) {
			printf("%d %d\n",j,sa-ret);
			return 0;
		}
	}
}