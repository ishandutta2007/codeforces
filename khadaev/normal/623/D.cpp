#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	forn(i, 0, n) cin >> p[i];
	ld prev = 0;
	vector<ld> find(n, 0.0);
	ld ans = 0.0;
	for(int ii = 0; ; ++ii) {
		ld max_prio = -1e18;
		int ind = -1;
		ld anyone = 1;
		forn(i, 0, n) anyone *= find[i];
		forn(i, 0, n) {
			if (find[i] < 1e-6) {
				ind = i;		
				break;
			}
			ld prio = anyone / find[i] * (find[i] + (1 - find[i]) *
			p[i]/ 100);
			if (prio > max_prio) {
				max_prio = prio;
				ind = i;
			}
		}
		find[ind] += (1 - find[ind]) * p[ind] / 100;
		anyone = 1;
		forn(i, 0, n) anyone *= find[i];
		//cout << ind << ' ' << find[ind] << '\n';
		//cout << noone << '\n';
		if (anyone - prev > 1e-12) ans += (anyone - prev) * (ii + 1);
		else if (prev > 1e-9) break;
		//cout << "PROB: " << 1 - anyone << '\n';
		prev = anyone;
		//cout << ans << '\n';
	}
	cout << fixed << setprecision(10) << ans << '\n';

	return 0;
}