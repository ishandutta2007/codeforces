#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[405][405];

list<int> e[160005];
list<int>::iterator gde[405][405];
int pre[405][405], posle[405][405];
int ban[405];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	int sol = 1;
	for (int l=0; l<n; l++) {
		for (int i=0; i<m; i++) {
			for (int j=l; j<n; j++) {
				int x = a[j][i];
				e[x].emplace_back(i);
				gde[j][i] = prev(e[x].end());
			}
		}
		for (int j=n-1; j>=l; j--) {
			// uzmi
			for (int i=0; i<m; i++) {
				int x = a[j][i];
				auto it = gde[j][i];
				if (it != e[x].begin())
					pre[j][i] = *prev(it);
				else
					pre[j][i] = m;
				++it;
				if (it != e[x].end())
					posle[j][i] = *it;
				else
					posle[j][i] = m;
			}
			// brisni
			for (int i=0; i<m; i++) {
				int x = a[j][i];
				e[x].erase(gde[j][i]);
			}
		}
		// resi glavno
		fill(ban, ban+m, m);
		for (int j=l; j<n; j++) {
			for (int i=0; i<m; i++) {
				mn(ban[pre[j][i]], i);
				mn(ban[i], posle[j][i]);
			}
			// sweep ban
			ban[m] = m;
			for (int i=m-1; i>=0; i--) {
				mn(ban[i], ban[i+1]);
				sol = max(sol, (j-l+1)*(ban[i]-i));
			}
		}
	}
	cout << sol << '\n';
}