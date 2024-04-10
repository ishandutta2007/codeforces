#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n;
ll p[100005], s[100005], a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++)
		cin >> p[i];
	for (int i=1; i<=n; i++)
		cin >> s[i];
	for (int i=2; i<=n; i++) {
		if (s[i] != -1) {
			if (s[p[p[i]]] > s[i]) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	for (int i=2; i<=n; i++) {
		if (s[i] == -1) {
			s[i] = 1123123123;
		} else {
			s[p[i]] = min(s[p[i]], s[i]);
		}
	}
	ll sol = 0;
	for (int i=1; i<=n; i++)
		if (s[i] == 1123123123)
			s[i] = s[p[i]];
	for (int i=1; i<=n; i++)
		sol += s[i] - s[p[i]];
	cout << sol << '\n';
}