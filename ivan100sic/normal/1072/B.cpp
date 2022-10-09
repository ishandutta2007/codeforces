#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];
bool d[100005][4];
int p[100005][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++)
		cin >> b[i];

	d[1][0] = d[1][1] = d[1][2] = d[1][3] = 1;

	for (int i=1; i<n; i++) {
		for (int old=0; old<4; old++) {
			if (!d[i][old])
				continue;
			for (int nu=0; nu<4; nu++) {
				if (((old | nu) == a[i]) && ((old & nu) == b[i])) {
					d[i+1][nu] = true;
					p[i+1][nu] = old;
				}
			}
		}
	}

	int v = -1;
	for (int i=0; i<4; i++)
		if (d[n][i])
			v = i;

	if (v == -1)
		return cout << "NO\n", 0;

	vector<int> sol;
	for (int i=n; i>=1; i--) {
		sol.push_back(v);
		v = p[i][v];
	}

	reverse(sol.begin(), sol.end());
	cout << "YES\n";
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}