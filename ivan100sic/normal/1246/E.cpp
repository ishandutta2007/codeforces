#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool d[1 << 16][2005];
unsigned char v[1 << 16][2005];
int n, k;
int a[16], f[2005], nx[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	for (int i=1; i<2005; i++)
		f[i] = i % k ? i : f[i/k];

	for (int i=k; i<2005; i+=k)
		nx[i] = i/k;

	d[0][0] = 1;
	for (int mask=0; mask<(1<<n); mask++) {
		for (int t=0; t<2005; t++) {
			if (!d[mask][t])
				continue;
			for (int j=0; j<n; j++) {
				if (mask & (1 << j))
					continue;
				for (int z = t + a[j], c = 0;; z = nx[z], c++) {
					d[mask | (1 << j)][z] = 1;
					v[mask | (1 << j)][z] = c + (j<<4);
					if (!nx[z]) break;
				}
			}
		}
	}

	vector<pair<int, int>> w;
	int mask = (1<<n)-1;
	int t = 1, u = 0;

	if (!d[mask][t]) {
		cout << "NO\n";
		return 0;
	}

	while (mask) {
		int c = v[mask][t];
		int j = c >> 4;
		int r = c & 15;
		w.push_back({u -= r, a[j]});
		while (r--)
			t *= k;
		t -= a[j];
		mask -= 1 << j;
	}

	cout << "YES\n";

	while (w.size() > 1) {
		sort(w.begin(), w.end());
		auto a = w[0], b = w[1];
		w.erase(w.begin(), w.begin()+2);
		cout << a.second << ' ' << b.second << '\n';
		int x = a.second + b.second, y = a.first;
		while (x % k == 0) {
			x /= k;
			y++;
		}
		w.emplace_back(y, x);
	}
}