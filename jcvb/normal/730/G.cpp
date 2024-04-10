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

const int N=210;
int n,s[N],t[N],v[N];
PII p[N];
bool valid(int l,int r,int n) {
	r=l+r-1;
	rep(i,1,n) {
		if (p[i].se>=l&&p[i].fi<=r) return 0;
	}
	return 1;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",s+i,t+i);
		if (valid(s[i],t[i],i)) {
			p[i]=mp(s[i],s[i]+t[i]-1);
			printf("%d %d\n",s[i],s[i]+t[i]-1);
		} else {
			rep(j,0,i) v[j]=p[j].se+1;
			sort(v,v+i);
			rep(j,0,i) if (valid(v[j],t[i],i)) {
				p[i]=mp(v[j],v[j]+t[i]-1);
				printf("%d %d\n",v[j],v[j]+t[i]-1);
				break;
			}
		}
	}
}