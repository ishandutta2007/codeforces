#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i=1; i<=n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({-a-b-c-d, i});
	}
	sort(v.begin(), v.end());
	for (int i=1; i<=n; i++)
		if (v[i-1].second == 1)
			cout << i;

}