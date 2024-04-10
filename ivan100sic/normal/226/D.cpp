#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[105][105], rs[105], cs[105], rf[105], cf[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	// 	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];
			// a[i][j] = uniform_int_distribution<int>(-100, 100)(eng);

	while (1) {
		// string _;
		// getline(cin, _);
		fill(rs, rs+n, 0);
		fill(cs, cs+m, 0);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				rs[i] += a[i][j];
				cs[j] += a[i][j];
				// cerr << a[i][j] << " \n"[j == n-1];
			}
		}
		bool found = 0;
		for (int i=0; i<n && !found; i++) {
			if (rs[i] < 0) {
				for (int j=0; j<m; j++)
					a[i][j] *= -1;
				found = 1;
				rf[i] ^= 1;
			}
		}
		for (int j=0; j<m && !found; j++) {
			if (cs[j] < 0) {
				for (int i=0; i<n; i++)
					a[i][j] *= -1;
				found = 1;
				cf[j] ^= 1;
			}
		}

		if (!found)
			break;
	}

	basic_string<int> p, q;

	for (int i=0; i<n; i++)
		if (rf[i])
			p += i+1;
	for (int j=0; j<m; j++)
		if (cf[j])
			q += j+1;

	cout << p.size();
	for (int x : p)
		cout << ' ' << x;
	cout << '\n';

	cout << q.size();
	for (int x : q)
		cout << ' ' << x;
	cout << '\n';
}