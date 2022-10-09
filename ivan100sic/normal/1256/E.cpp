#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll d[200005];
int n;
pair<int, int> a[200005];
int s[200005], t[200005], p[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n);
	memset(d, 63, sizeof d);
	d[0] = 0;
	for (int i=3; i<=n; i++) {
		for (int j=3; j<=min(8, i); j++) {
			ll v = a[i-1].first - a[i-j].first + d[i-j];
			if (v < d[i]) {
				d[i] = v;
				p[i] = j;
			}
		}
	}
	cout << d[n] << ' ';
	int q = 0;
	for (int j=n; j; j-=p[j]) {
		fill(s+j-p[j], s+j, ++q);
	}
	cout << q << '\n';
	for (int i=0; i<n; i++)
		t[a[i].second] = s[i];
	for (int i=0; i<n; i++)
		cout << t[i] << " \n"[i == n-1];
}