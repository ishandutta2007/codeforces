#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

int b[400005], w[400005];

main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	set<pr<int, int> > menshe;
	set<pr<int, int> > bolshe;
	for (int i = 0; i < n; i++) {
		cin >> b[i] >> w[i];
		if (i > 0) {
			if (b[i] > b[0]) {
				bolshe.insert(mp(w[i] - b[i] + 1, i));
			}
			else {
				menshe.insert(mp(-1 * b[i], i));
			}
		}
	}
	int ans = bolshe.size();
	while (b[0] && !bolshe.empty()) {
		auto p = *bolshe.begin();
		bolshe.erase(bolshe.begin());
		if (p.fs > b[0]) {
			cout << ans + 1;
			return 0;
		}
		b[0] -= p.fs;
		while (!menshe.empty() && -1*menshe.begin()->fs > b[0]) {
			int i = menshe.begin() -> sc;
			bolshe.insert(mp(w[i] - b[i] + 1, i));
			menshe.erase(menshe.begin());
		}
		ans = min(ans, len(bolshe));
	}
	cout << ans + 1;
	return 0;
}