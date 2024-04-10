#include <bits/stdc++.h>
#define mmax(a,b) a=max(a,b)
using namespace std;
typedef long long ll;
string s;
ll num[10],base[11],fact[19],cur[10];
bool zero;
ll fun(ll x) {
	ll i,j;
	for (i = 0; i <= 9; i++) {
		cur[i] = (x%base[i + 1]) / base[i];
		if (cur[i] == 0 && num[i] != 0)return 0;
	}
	ll ans = 1,l=0;
	for (i = 9; i >= 0; i--) {
		for (j = 1; j <= cur[i]; j++) {
			ans *= l + (i != 0||(!zero));
			l++;
		}
		ans /= fact[cur[i]];
	}
	return ans;
}
int main() {
	ll i;
	cin >> s;
	for (char c : s)num[c - '0']++;
	zero = num[0] > 0;
	vector<int> idk;
	for (i = 0; i <= 9; i++)if (num[i] != 0)idk.push_back(num[i]);
	memset(num, 0, sizeof(num));
	for (i = 0; i < idk.size(); i++)num[i] = idk[i];
	base[0] = 1;
	for (i = 1; i <= 10; i++)base[i] = base[i - 1] * (num[i-1] + 1);
	fact[0] = 1;
	for (i = 1; i <= 19; i++)fact[i] = fact[i - 1] * i;
	ll ans = 0;
	for (i = 0; i < base[10]; i++) {
		ans += fun(i);
	}
	printf("%lld", ans);
	getchar(); getchar();
}