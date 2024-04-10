#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	k--;
	int sol = 0;
	int h = n / 2, l = 123123123, r = -1;
	for (int i=0; i<h; i++) {
		int j = n-1-i;
		if (s[i] != s[j]) {
			l = min(l, i);
			r = max(r, i);
			sol += min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
		}
	}
	if (k >= h)
		k = n-1-k;
	if (sol)
		sol += r-l + min(abs(k-l), abs(k-r));
	cout << sol << '\n';
}