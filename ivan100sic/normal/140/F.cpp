#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> a[200005], b[200005], c[200005];
int n, k;

void ph(int x) {
	if (x < 0) {
		cout << "-";
		x = -x;
	}
	cout << x/2 << "." << x%2*5;
}

vector<pair<int, int>> sol;

void probaj(int x, int y) {
	for (int i=0; i<n; i++) {
		b[i].first += x;
		b[i].second += y;
	}
	int z = set_intersection(a, a+n, b, b+n, c) - c;
	for (int i=0; i<n; i++) {
		b[i].first -= x;
		b[i].second -= y;
	}

	if (z >= n-k) {
		sol.push_back({x, y});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a+n);
	for (int i=0; i<n; i++)
		b[i] = {-a[i].first, -a[i].second};
	reverse(b, b+n);
	if (n == k) {
		cout << "-1\n";
		return 0;
	}

	for (int i=0; i<=k; i++) {
		for (int j=n-k-1; j<n; j++) {
			probaj(a[i].first + a[j].first, a[i].second + a[j].second);
		}
	}

	sort(sol.begin(), sol.end());
	sol.erase(unique(sol.begin(), sol.end()), sol.end());

	cout << sol.size() << '\n';
	for (auto p : sol) {
		ph(p.first);
		cout << ' ';
		ph(p.second);
		cout << '\n';
	}
}