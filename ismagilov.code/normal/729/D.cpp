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

main() {
	ios_base::sync_with_stdio(0);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	bool popal[n];
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		popal[i] = (s[i] == '1');
	}
	int prev = -1;
	int tekko = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (popal[i]) {
			prev = i;
		}
		if ((i - prev) == b) {
			if (a == 1) {
				ans.pb(i);
				prev = i;
			}
			else {
				a--;
				prev = i;
			}
		}
	}
	cout << len(ans) << endl;
	for (auto v : ans) {
		cout << v + 1 << ' ';
	}
}