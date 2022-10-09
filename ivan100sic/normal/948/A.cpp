#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[666];
int n, m;

void no() {
	cout << "No\n";
	exit(0);
}

bool w(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	return s[x][y] == 'W';
}

void check(int i, int j) {
	if (s[i][j] != 'S')
		return;
	if (w(i-1, j))
		no();
	if (w(i+1, j))
		no();
	if (w(i, j-1))
		no();
	if (w(i, j+1))
		no();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (s[i][j] == '.')
				s[i][j] = 'D';

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			check(i, j);

	cout << "Yes\n";
	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}