#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m, n;
string s;
int nx[100005][26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> s;
	n = s.size();
	fill(nx[n], nx[n] + 26, n);
	for (int i=n-1; i>=0; i--) {
		copy(nx[i+1], nx[i+1] + 26, nx[i]);
		nx[i][s[i] - 'a'] = i;
	}

	for (char x = 'a'; x <= 'z'; x++) {
		// da li moze?
		vector<int> v = {-1};

		for (int i=0; i<n; i++)
			if (s[i] <= x)
				v.push_back(i);

		v.push_back(n);

		int ok = 1;

		for (int j=0; j<(int)v.size()-1; j++)
			if (v[j+1] - v[j] > m)
				ok = 0;

		if (!ok) {
			continue;
		}

		// popuni svim manjim i zavrsavaj
		vector<int> idx = {-1};
		string sol;
		for (int i=0; i<n; i++)
			if (s[i] < x) {
				idx.push_back(i);
				sol += s[i];
			}
		idx.push_back(n);

		vector<int> extra;
		set<int> aovi;
		for (int i=0; i<n; i++)
			if (s[i] == x)
				aovi.insert(i);

		for (int j=0; j<(int)idx.size() - 1; j++) {
			int l = idx[j];
			int r = idx[j+1];

			while (r - l > m) {
				auto it = aovi.upper_bound(l + m);
				--it;

				extra.push_back(*it);
				l = *it;
				aovi.erase(it);
			}
		}

		for (int x : extra)
			sol += s[x];

		sort(sol.begin(), sol.end());
		cout << sol;
		return 0;
	}
}