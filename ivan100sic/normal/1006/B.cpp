#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		v.push_back({x, i});
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	vector<int> p(k);
	int z = 0;
	for (int i=0; i<k; i++) {
		p[i] = v[i].second;
		z += v[i].first;
	}
	sort(p.begin(), p.end());
	cout << z << '\n';
	for (int i=0; i<k-1; i++)
		cout << (i ? p[i]-p[i-1] : p[i]) << ' ';
	if (k > 1)
		cout << n - p[k-2];
	else
		cout << n << '\n';
}