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

	string s;
	cin >> s;
	int n = s.size();

	map<char, vector<string>> buc;

	for (int i=0; i<n; i++) {
		string p = s;
		rotate(p.begin(), p.begin() + i, p.end());
		buc[p[0]].emplace_back(move(p));
	}

	int sol = 0;

	for (auto& [x, v] : buc) {
		// nadji broj unique slova za svaku kolonu
		vector<int> rez(n, 0);
		for (int j=1; j<n; j++) {
			int f[26] = {0};
			for (auto& s : v)
				f[s[j] - 'a']++;
			rez[j] = count(f, f+26, 1);
		}
		sol += *max_element(rez.begin(), rez.end());
	}

	cout << setprecision(20) << fixed << (ld)sol/n << '\n';
}