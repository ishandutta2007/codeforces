#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, t;
bool e[1000000];
int lcp[1000000];
ll dp[1000000], dp1[1000000], dp2[1000000],mod=1000000007;
int main() {
	cin >> s >> t;
	int n = s.size(), m = t.size(),i,j;
	for (i = 1,j=0; i < m; ) {
		if (t[i] == t[j])lcp[i++] = ++j;
		else if(j)j=lcp[j-1];
		else i++;
	}
	for (i = 0, j = 0; i < n;) {
		if (j == m)e[i-1] = 1,j=lcp[j-1];
		else if (s[i] == t[j])i++, j++;
		else if (j)j=lcp[j-1];
		else i++;
	}
	if (j == m)e[i - 1] = 1;
	if (m == 1 && s[0] == t[0])dp[0] = dp1[0] = dp2[0] = 1;
	for (i = 1; i < n; dp1[i]=(dp1[i-1]+dp[i])%mod,dp2[i]=(dp2[i-1]+dp1[i])%mod,i++) {
		if (!e[i])dp[i] = dp[i - 1];
		else dp[i] = (dp2[i-m]+i-m+2) % mod;
	}
	printf("%lld", dp1[n - 1]);
}