#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	vector<string> sol;

	int ii = 0;
	for (int i=1; i<n; i++)
		if (a[i][0] < a[ii][0])
			ii = i;

	for (int i=0; i<n; i++) {
		while (a[i][0] > a[ii][0]) {
			sol.push_back(string("row ") + to_string(i+1));
			for (int j=0; j<m; j++)
				a[i][j]--;
		}
	}

	int jj = 0;
	for (int j=1; j<m; j++)
		if (a[0][j] < a[0][jj])
			jj = j;

	for (int j=0; j<m; j++) {
		while (a[0][j] > a[0][jj]) {
			sol.push_back(string("col ") + to_string(j+1));
			for (int i=0; i<n; i++)
				a[i][j]--;
		}
	}

	// svi isti i >= 0
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j] != a[0][0] || a[i][j] < 0)
				return cout << "-1\n", 0;
	//

	if (n < m) {
		for (int i=0; i<n; i++)
			for (int x=0; x<a[0][0]; x++)
				sol.push_back(string("row ") + to_string(i+1));
	} else {
		for (int j=0; j<m; j++)
			for (int x=0; x<a[0][0]; x++)
				sol.push_back(string("col ") + to_string(j+1));
	}

	cout << sol.size() << '\n';
	for (string s : sol)
		cout << s << '\n';
}