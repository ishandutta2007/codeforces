#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000000;

int a[200009], l[200009], pp[200009];
bool vs[1000009], pr[1000009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= N; i++) {
		if (vs[i]) continue;
		pr[i] = true;
		for (int j = i; j <= N; j += i)
			vs[j] = true;
	}
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, e; cin >> n >> e;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == 1) a[i] = 0;
			else if (pr[a[i]]) a[i] = 1;
			else a[i] = 2;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				if (e < i && l[i - e] != -1) {
					if (pp[i - e] != -1) ans += (pp[i - e] - l[i - e]) / e + 1;
					l[i] = l[i - e];
					pp[i] = pp[i - e];
				}
				else {
					l[i] = i;
					pp[i] = -1;
				}
			}
			else if (a[i] == 1) {
				if (e < i && l[i - e] != -1) {
					if (pp[i - e] != -1) {
						ans += (i - pp[i - e]) / e - 1;
						l[i] = pp[i - e] + e;
						pp[i] = i;
					}
					else {
						ans += (i - l[i - e]) / e;
						l[i] = l[i - e];
						pp[i] = i;
					}
				}
				else {
					l[i] = i;
					pp[i] = i;
				}
			}
			else {
				l[i] = pp[i] = -1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}