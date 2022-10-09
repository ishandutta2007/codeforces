#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<pair<int, int>> L, R;
char s[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	for (int i=1; i<=50; i++)
		for (int j=1; j<=50; j++) {
			s[i][j] = j <= 25 ? 'A' : 'B';
			if (i%2 && j%2) {
				if (j < 25)
					L.push_back({i, j});
				else if (j > 26)
					R.push_back({i, j});
			}
		}
	a--;
	b--;

	while (a--) {
		auto p = R.back();
		R.pop_back();
		s[p.first][p.second] = 'A';
	}

	while (b--) {
		auto p = L.back();
		L.pop_back();
		s[p.first][p.second] = 'B';
	}

	while (c--) {
		if (R.size()) {
			auto p = R.back();
			R.pop_back();
			s[p.first][p.second] = 'C';
		} else {
			auto p = L.back();
			L.pop_back();
			s[p.first][p.second] = 'C';
		}
	}

	while (d--) {
		if (R.size()) {
			auto p = R.back();
			R.pop_back();
			s[p.first][p.second] = 'D';
		} else {
			auto p = L.back();
			L.pop_back();
			s[p.first][p.second] = 'D';
		}
	}

	cout << "50 50\n";
	for (int i=1; i<=50; i++) {
		for (int j=1; j<=50; j++)
			cout << s[i][j];
		cout << '\n';
	}
}