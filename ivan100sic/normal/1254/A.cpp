#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (char x='a'; x<='z'; x++)
		P += x;
	for (char x='A'; x<='Z'; x++)
		P += x;
	for (char x='0'; x<='9'; x++)
		P += x;

	int t;
	cin >> t;
	while (t--) {
		int n, m, k, w = 0;
		cin >> n >> m >> k;
		vector<string> a(n), b(n, string(m, 0));
		for (int i=0; i<n; i++) {
			cin >> a[i];
			for (char c : a[i])
				w += c == 'R';
		}
		vector<pair<int, int>> t;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				t.emplace_back(i, j);
			}
		}
		sort(t.begin(), t.end(), [](auto p, auto q) {
			if (p.first != q.first)
				return p.first < q.first;
			if (p.first % 2)
				return p.second > q.second;
			else
				return p.second < q.second;
		});

		int u = 0, c = 0;
		for (int i=0; i<n*m; i++) {
			auto [x, y] = t[i];
			if (a[x][y] == 'R')
				c++;
			b[x][y] = P[u];
			if (c == w*(u+1)/k && u != k-1)
				u++;
		}

		for (int i=0; i<n; i++)
			cout << b[i] << '\n';
	}
}