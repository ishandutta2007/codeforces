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

const int N=3010;
int dp[3][N][N],n,p,s,a[N],b[N];
pair<PII,int> q[N];
VI va,vb;
void dfs(int ty,int n,int a,int b) {
	if (n==0) return;
	if (n==a+b) ty=0;
//	printf("%d %d %d %d\n",ty,n,a,b);
	if (ty==1) {
//		printf("%d\n",dp[1][n][a]);
		assert(b==s);
		if (dp[1][n-1][a]==dp[1][n][a]) dfs(1,n-1,a,b);
		else {
			assert(a>=1&&dp[1][n-1][a-1]+q[n].fi.fi==dp[1][n][a]);
			va.pb(q[n].se);
			dfs(1,n-1,a-1,b);
		}
	} else if (ty==2) {
//		printf("%d\n",dp[2][n][b]);
		assert(a==p);
		if (dp[2][n-1][b]==dp[2][n][b]) dfs(2,n-1,a,b);
		else {
			assert(b>=1&&dp[2][n-1][b-1]+q[n].fi.se==dp[2][n][b]);
			vb.pb(q[n].se);
			dfs(2,n-1,a,b-1);
		}
	} else {
//		printf("%d\n",dp[0][n][a]);
		if (a>=1&&dp[0][n-1][a-1]+q[n].fi.fi==dp[0][n][a]) {
			va.pb(q[n].se);
			dfs(0,n-1,a-1,b);
		} else {
			assert(b>=1&&dp[0][n-1][a]+q[n].fi.se==dp[0][n][a]);
			vb.pb(q[n].se);
			dfs(0,n-1,a,b-1);
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&p,&s);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) scanf("%d",b+i),q[i]=mp(mp(a[i],b[i]),i);
	sort(q+1,q+n+1); reverse(q+1,q+n+1);
//	rep(i,1,n+1) printf("%d %d\n",q[i].fi.fi,q[i].fi.se);
	memset(dp,0xe0,sizeof(dp));
	dp[0][0][0]=0;
	rep(i,0,n) {
		rep(j,0,p+1) if (dp[1][i][j]>=0) {
			if (j<p) dp[1][i+1][j+1]=max(dp[1][i+1][j+1],dp[1][i][j]+q[i+1].fi.fi);
			dp[1][i+1][j]=max(dp[1][i+1][j],dp[1][i][j]);
		}
		rep(j,0,s+1) if (dp[2][i][j]>=0) {
			if (j<s) dp[2][i+1][j+1]=max(dp[2][i+1][j+1],dp[2][i][j]+q[i+1].fi.se);
			dp[2][i+1][j]=max(dp[2][i+1][j],dp[2][i][j]);
		}
		rep(j,0,p+1) if (dp[0][i][j]>=0) {
			if (i-j<s) {
				dp[0][i+1][j]=max(dp[0][i+1][j],dp[0][i][j]+q[i+1].fi.se);
			}
			if (j<p) {
				dp[0][i+1][j+1]=max(dp[0][i+1][j+1],dp[0][i][j]+q[i+1].fi.fi);
			}
		}
		if (i+1>=s&&i+1<=p+s) dp[1][i+1][i+1-s]=max(dp[1][i+1][i+1-s],dp[0][i+1][i+1-s]);
		if (i+1>=p&&i+1<=p+s) dp[2][i+1][i+1-p]=max(dp[2][i+1][i+1-p],dp[0][i+1][p]);
	}
	printf("%d\n",max(dp[1][n][p],dp[2][n][s]));
	if (dp[1][n][p]>dp[2][n][s]) {
		dfs(1,n,p,s);
	} else {
		dfs(2,n,p,s);
	}
	for (auto v:va) printf("%d ",v); puts("");
	for (auto v:vb) printf("%d ",v); puts("");
}