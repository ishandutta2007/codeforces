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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> a(n);
		int t[2] = {0, 0}, x[2] = {0, 0};
		for (auto& s : a) {
			cin >> s;
			if (s[0] != s.back())
				t[s[0]-'0']++;
			else
				x[s[0]-'0']++;
		}

		if (t[0] + t[1] == 0 && x[0] && x[1]) {
			cout << "-1\n";
			continue;
		}

		set<string> ima(a.begin(), a.end());
		int k = 0;
		vector<int> sol;
		for (auto s : a) {
			string r = s;
			k++;
			reverse(r.begin(), r.end());
			if (s[0] != s.back() && !ima.count(r)) {
				if (s[0] == '0' && t[0] - t[1] > 1) {
					t[0]--;
					t[1]++;
					sol.push_back(k);
				} else if (s[0] == '1' && t[1] - t[0] > 1) {
					t[1]--;
					t[0]++;
					sol.push_back(k);
				}
			}
		}

		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}
}