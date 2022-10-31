// Hydro submission #635a69bc761b032d5629a01a@1666869692577
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define SET(a,b) memset(a,b,sizeof(a))
int read() {
	int a=0, f=1; char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) a=a*10+c-'0', c=getchar();
	return a*f;
}
const int N=1e5+5;
int t, n, a[N], d[N];
void solve() {
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(), d[a[i]]=i+1;
	for(int i=1;i<=n;++i) printf("%lld ",min(d[i],n));
	puts("");
}
signed main() {
	t=read();
	while(t--) solve();
}