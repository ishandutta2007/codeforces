#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

const ld PI = acos(-1.0);
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans;
	int d = 1;
	while (n) {
		if (n % 2) ans.push_back(d);
		n /= 2;
		d++;
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans) cout << i << ' ';
	return 0;
}