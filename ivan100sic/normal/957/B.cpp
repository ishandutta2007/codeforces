#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[50];
int vc;
set<int> rows, cols;
bool u[50][50];

void dfs(int x, int y) {
	u[x][y] = 1;
	vc++;
	rows.insert(x);
	cols.insert(y);
	for (int i=0; i<n; i++) {
		if (!u[i][y] && s[i][y] == '#')
			dfs(i, y);
	}
	for (int j=0; j<m; j++) {
		if (!u[x][j] && s[x][j] == '#')
			dfs(x, j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!u[i][j] && s[i][j] == '#') {
				vc = 0;
				rows.clear();
				cols.clear();
				dfs(i, j);
				if (vc != (int)(rows.size() * cols.size())) {
					cout << "No\n";
					return 0;
				}
			}
		}
	}
	cout << "Yes\n";
}