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
int n,c[N],d[N],dp[N][N],a,b;
vector<PII> l,r;
int ff(int x,int y) {
	VI v;
	rep(i,0,x) v.pb(l[i].fi+l[i].se);
	rep(i,x+1,a) v.pb(l[i].fi);
	rep(i,0,y) v.pb(r[i].fi+r[i].se);
	rep(i,y,b) v.pb(r[i].fi);
	int c=0;
	for (auto p:v) if (p>=l[x].fi&&p<=l[x].fi+l[x].se) c++;
	return c;
}
int gg(int x,int y) {
	VI v;
	rep(i,0,x) v.pb(l[i].fi+l[i].se);
	rep(i,x,a) v.pb(l[i].fi);
	rep(i,0,y) v.pb(r[i].fi+r[i].se);
	rep(i,y+1,b) v.pb(r[i].fi);
	int c=0;
	for (auto p:v) if (p<=r[y].fi&&p>=r[y].fi+r[y].se) c++;
	return c;

}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",c+i,d+i);
		c[i]=c[i]*10000+n-i;
		d[i]=d[i]*10000;
		if (d[i]>=0) l.pb(mp(c[i],d[i]));
		else r.pb(mp(c[i],d[i]));
	}
	sort(all(l)); sort(all(r)); reverse(all(r));
	a=SZ(l),b=SZ(r);
	memset(dp,0xe0,sizeof(dp));
	dp[0][0]=0;
	rep(i,0,a+1) rep(j,0,b+1) if (dp[i][j]>=0) {
		if (i<a) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+ff(i,j));
		if (j<b) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+gg(i,j));
	}
	printf("%d\n",dp[a][b]);
}