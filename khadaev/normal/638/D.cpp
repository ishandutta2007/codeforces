#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

const int MAXN = 100;
int n, m, k;
bool a[MAXN][MAXN][MAXN];

bool check(vector<int> v) {
	int x = v[0], y = v[1], z = v[2];
	return 0 <= x && x < n && 0 <= y && y < m && 0 <= z && z < k && a[x][y][z];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	char c;
	forn(x, 0, n)
		forn(y, 0, m)
			forn(z, 0, k) {
				cin >> c;
				a[x][y][z] = c == '1';
			}
	int ans = 0;
	forn(x, 0, n)
		forn(y, 0, m)
			forn(z, 0, k)
				if (a[x][y][z]) {
					bool crit = false;
					vector<int> v = {x, y, z};
					forn(i, 0, 3)
						forn(j, 0, 3) {
							bool local = true;
							if (i == j) {
								vector<int> w = v;
								w[i]++;
								local &= check(w);
								w = v;
								w[i]--;
								local &= check(w);
							} else {
								vector<int> w = v;
								w[i]++;
								local &= check(w);
								w = v;
								w[j]--;
								local &= check(w);
								w[i]++;
								local &= !check(w);
							}
							crit |= local;
						}
					if (crit) ++ans;
				}
	cout << ans << '\n';
	return 0;
}