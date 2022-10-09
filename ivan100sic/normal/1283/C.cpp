#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a[200005], b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i])
			b[a[i]] = i;
	}

	vector<pair<int, int>> e;

	for (int i=1; i<=n; i++) {
		if (b[i] == 0) {
			int h = i;
			int t = h;
			while (a[t])
				t = a[t];
			e.emplace_back(h, t);
		}
	}
	int k = e.size();
	for (int i=0; i<k; i++) {
		a[e[i].second] = e[(i+1)%k].first;
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << " \n"[i == n];
}