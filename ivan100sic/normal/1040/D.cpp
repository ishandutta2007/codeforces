#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ask(ll l, ll r) {
	cout << l << ' ' << r << '\n' << flush;
	string s;
	cin >> s;

	if (s == "Yes" && l == r)
		exit(0);

	return s == "Yes";
}

int pusiteKuracRandomizovaniZadaciSaHakovanjem() {
	srand(time(nullptr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pusiteKuracRandomizovaniZadaciSaHakovanjem();

	ll n, k;
	cin >> n >> k;

	ll l = 1, r = n;
	while (1) {
		if (r-l >= 50) {
			ll m = (r+l) / 2;

			bool a = ask(l, m);

			ll lt, rt;

			if (a) {
				lt = max(l-k, 1ll);
				rt = min(m+k, n);			
			} else {
				lt = max(m+1-k, 1ll);
				rt = min(r+k, n);
			}

			l = lt;
			r = rt;
		} else {
			ll m = l + rand() % (r-l+1);

			ask(m, m);
			l = max(l-k, 1ll);
			r = min(r+k, n);
		}
	}
}