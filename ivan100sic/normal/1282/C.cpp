#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int qq;
	cin >> qq;
	while (qq--) {
		int n, T;
		ll a, b;
		cin >> n >> T >> a >> b;
		basic_string<int> tp = {0, T, T-1};
		map<int, basic_string<int>> e;
		vector<int> tipz(n), vrez(n);
		int ma = 0, mb = 0, ua = 0, ub = 0;
		for (int i=0; i<n; i++)
			cin >> tipz[i], (tipz[i] ? ub : ua)++;
		for (int i=0; i<n; i++)
			cin >> vrez[i];
		for (int i=0; i<n; i++) {
			e[vrez[i]] += tipz[i];
			tp += vrez[i];
			if (vrez[i])
				tp += vrez[i] - 1;
		}
		sort(tp.begin(), tp.end());
		tp.erase(unique(tp.begin(), tp.end()), tp.end());
		auto it = e.begin();
		int sol = 0;
		for (int t : tp) {
			if (it != e.end() && t == it->first) {
				for (int x : it->second) {
					(x ? mb : ma)++;
					(x ? ub : ua)--;
				}
				++it;
			}
			if (ma*a + mb*b <= t) {
				int q = (t - ma*a - mb*b) / a;
				if (q <= ua) {
					sol = max(sol, ma + mb + q);
				} else {
					int r = (t - ma*a - mb*b - ua*a) / b;
					sol = max(sol, ma + mb + ua + min(r, ub));
				}
			}
		}
		cout << sol << '\n';
	}	
}