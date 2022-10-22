#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		string s, t; cin >> s >> t;
		vector<int> v[30];
		for (int i=0; i<s.size(); i++) {
			v[s[i]-'a'].push_back(i);
		}

		bool flag = true;
		int p = -1, c = 1;
		for (int i=0; i<t.size(); i++) {
			if (v[t[i]-'a'].empty()) {
				flag = false;
				break;
			}
			int k = t[i]-'a';
			int t = lower_bound(v[k].begin(), v[k].end(), p+1) - v[k].begin();

			if (t == v[k].size()) {
				++c;
				p = v[k].front();
			}
			else p = v[k][t];
		}

		if (!flag) cout << "-1\n";
		else cout << c << '\n';
	}
}