#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	int p, g, i, t;
	bool operator< (const stvar& b) const {
		return tie(p, t) < tie(b.p, b.t);
	}
};

vector<stvar> a;
ll ans[100005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.push_back({x, 0, i, 1});
	}
	for (int j=0; j<m; j++) {
		int d, g;
		cin >> d >> g;
		a.push_back({d, g, j, 0});
	}
	sort(a.begin(), a.end());
	ll q = 0;
	for (auto& [p, g, i, t] : a) {
		q += g;
		if (t)
			ans[i] = q;
	}
	for (int i=0; i<n; i++)
		cout << ans[i] << " \n"[i == n-1];
}