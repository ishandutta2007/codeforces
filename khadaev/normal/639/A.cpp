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
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> t(n + 1);
	t[n] = 0;
	vector<int> a(k, n);
	forn(i, 0, n) cin >> t[i];
	while (q-->0) {
		int type, id;
		cin >> type >> id;
		--id;
		if (type == 2) {
			bool found = false;
			forn(i, 0, k) if (a[i] == id) found = true;
			cout << (found ? "YES\n" : "NO\n");
		} else {
			forn(i, 0, k) {
				if (t[id] > t[a[i]]) {
					for (int j = k - 1; j > i; --j) {
						a[j] = a[j - 1];
					}
					a[i] = id;
					//cout << i << "!\n";
					break;
				}
			}	
			//forn(i, 0, k) cout << a[i] << ' ';
			//cout << '\n';
		}
	}
	return 0;
}