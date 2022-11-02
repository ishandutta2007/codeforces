#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

int r[100009];
ll a[100009], c[100009];
pair<ll, int> sp[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sp[i] = make_pair(c[i], i);
	}
	sort(sp + 1, sp + n + 1);
	for (int i = 1; i <= n; i++)
		r[i] = sp[i].second;
	int p = 1;
	for (int i = 0; i < m; i++) {
		int t; ll d; cin >> t >> d;
		if (a[t] >= d) {
			a[t] -= d;
			cout << c[t] * d << '\n';
		}
		else {
			ll s = 0;
			d -= a[t]; s += a[t] * c[t]; a[t] = 0;
			bool f = true;
			while (true) {
				if (p > n) {
					f = false;
					break;
				}
				if (d <= a[r[p]]) {
					a[r[p]] -= d;
					s += d * c[r[p]];
					break;
				}
				else {
					d -= a[r[p]];
					s += a[r[p]] * c[r[p]];
					a[r[p]] = 0;
					p++;
				}
			}
			if (f)
				cout << s << '\n';
			else
				cout << 0 << '\n';
		}
	}
	return 0;
}