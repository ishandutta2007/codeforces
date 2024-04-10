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
int n,m,l[N],val[N],a[N];
char s[N][N],t[N];
bool match(int v) {
	int c=strlen(s[v]);
	if (c!=l[0]) return 0;
	rep(i,0,l[0]) if (t[i]!='?'&&s[v][i]!=t[i]) return 0;
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%s",s[i]);
	rep(i,0,m) {
		scanf("%d",a+i);
		l[i]=strlen(s[a[i]]);
		val[a[i]]=1;
	}
	rep(i,1,m) if (l[i]!=l[0]) {
		puts("No");
		return 0;
	}
	rep(k,0,l[0]) {
		t[k]=s[a[0]][k];
		rep(i,1,m) if (s[a[i]][k]!=s[a[0]][k]) t[k]='?';
	}
	rep(i,1,n+1) if (!val[i]) {
		if (match(i)) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	puts(t);
}