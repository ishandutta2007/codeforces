// Hydro submission #62c19695fb4a7c72454a35b0@1656854166580
#include <bits/stdc++.h>
using namespace std;
char s[500001];
int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int l, r, ll, rr;
	for (l = 1; (l <= len) && (s[l] != '['); l++);
	for (r = len; (r > 0) && (s[r] != ']'); r--);
	for (ll = l + 1; (ll < r) && (s[ll] != ':'); ll++);
	for (rr = r - 1; (rr > ll) && (s[rr] != ':'); rr--);
	if (l >= r || ll >= rr) {
		printf("-1");
		return 0;
	}
	int cnt = 4;
	for (int i = ll + 1; i < rr; i++) {
		if (s[i] == '|') cnt++;
	}
	printf("%d", cnt);
	return 0;
}