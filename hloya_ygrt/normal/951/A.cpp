#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 1e9;
const int base = 1e9 + 7;
const double eps = 1e-7;
const int maxn = 100500;
const ll llinf = 1e18;



int main() {
	srand(time(NULL));
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	s += s;

	int r = -1;
	int ans = 0;
	for (int l = 0; l < s.size();) {
		int st = s[l];
		if (r < l) r = l;
		while (r + 1 < s.size() && s[r + 1] != s[r]) r++;
		ans = max(ans, r - l + 1);
		l = r + 1;
	}
	cout << min(ans, (int)s.size() / 2);
	return 0;
}