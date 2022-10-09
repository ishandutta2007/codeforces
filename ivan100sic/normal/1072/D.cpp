#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string s[2005];
int a[2005][2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i > 0)
				a[i][j] = max(a[i][j], a[i-1][j]);
			if (j > 0)
				a[i][j] = max(a[i][j], a[i][j-1]);
			if (s[i][j] == 'a')
				a[i][j] += 1;
		}
	}

	int dist = -1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i+j+1 - a[i][j] <= k) {
				dist = max(dist, i+j);
			}
		}
	}

	basic_string<pair<int, int>> pos;
	string sol;

	if (dist == -1) {
		pos = {{0, 0}};
		sol = s[0][0];
	} else {
		sol = string(dist+1, 'a');
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (i+j+1 - a[i][j] <= k && i+j == dist) {
					pos += {i, j};
				}
			}
		}
	}

	while ((int)sol.size() < 2*n-1) {
		basic_string<pair<int, int>> tmp;

		char minLetter = 'z';

		for (auto p : pos) {
			if (p.first < n-1)
				minLetter = min(minLetter, s[p.first + 1][p.second]);
			if (p.second < n-1)
				minLetter = min(minLetter, s[p.first][p.second + 1]);
		}

		for (auto p : pos) {
			if (p.first < n-1 && s[p.first + 1][p.second] == minLetter)
				tmp += {p.first + 1, p.second};
			if (p.second < n-1 && s[p.first][p.second + 1] == minLetter)
				tmp += {p.first, p.second + 1};
		}

		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

		sol += minLetter;

		swap(pos, tmp);
	}

	cout << sol << '\n';
}