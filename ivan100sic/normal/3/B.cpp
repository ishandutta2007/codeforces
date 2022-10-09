#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, v;
vector<pair<int, int>> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> v;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		(x == 1 ? a : b).emplace_back(y, i);
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>());
	sort(b.begin(), b.end(), greater<pair<int, int>>());

	vector<int> ps(a.size() + 1, 0);
	for (int i=0; i<(int)a.size(); i++)
		ps[i+1] = ps[i] + a[i].first;

	int oval = -1, ok = -1, curr = 0;

	for (int k=0; k<=(int)b.size(); k++) {
		if (2*k > v)
			break;
		int val = curr + ps[clamp(v-2*k, 0, (int)a.size())];
		if (val > oval) {
			oval = val;
			ok = k;
		}

		if (k != (int)b.size()) {
			curr += b[k].first;
		}
	}

	cout << oval << '\n';
	int l = clamp(v-2*ok, 0, (int)a.size());
	vector<int> sol;
	for (int i=0; i<l; i++)
		sol.emplace_back(a[i].second);
	for (int i=0; i<ok; i++)
		sol.emplace_back(b[i].second);
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}