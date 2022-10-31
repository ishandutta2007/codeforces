// Hydro submission #635a8327761b032d5629cce4@1666876200671
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
const int N=5e5+5;
int t, n;
char s[N];
void solve() {
	n=read();
	scanf("%s",s+1);
	int l=1, r=1;
	int ans=0;
	while(l<n) {
		if(s[l]=='('||(s[l]==')'&&s[l+1]==')')) l+=2;
		else {
			r=l+1;
			while(r<=n&&s[r]!=')') ++r;
			if(r>n) break;
			l=r+1;
		}
		++ans;
	}
	printf("%lld %lld\n",ans,n-l+1);
}
signed main() {
	t=read();
	while(t--) solve();
}