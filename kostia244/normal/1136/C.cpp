#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define maxn 300005
#define mod 1000000007ll
using namespace std;

int n, m, a[505][505], b[505][505], k = 1;
multiset<int> s[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	for (int ti = 0; ti < n; ti++) {
		int i = ti, j = 0;
		s[0].clear();
		s[1].clear();
		while (i >= 0 && j < m) {
			s[0].insert(a[i][j]);
			i--, j++;
		}
		i = ti, j = 0;
		while (i >= 0 && j < m) {
			s[1].insert(b[i][j]);
			i--, j++;
		}
		if (s[0] != s[1])
			return cout << "NO\n", 0;
	}
	for (int tj = 0; tj < m; tj++) {
		int i = n - 1, j = tj;
		s[0].clear();
		s[1].clear();
		while (i >= 0 && j < m) {
			s[0].insert(a[i][j]);
			i--, j++;
		}
		i = n - 1, j = tj;
		while (i >= 0 && j < m) {
			s[1].insert(b[i][j]);
			i--, j++;
		}
		if (s[0] != s[1])
			return cout << "NO\n", 0;
	}
	return cout << "YES\n", 0;
	return 0;
}