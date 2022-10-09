#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int z[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	while (n--) {
		int l, r;
		cin >> l >> r;
		z[l]++;
		z[r+1]--;
	}

	int c = 0;
	vector<int> v;
	for (int i=1; i<=m; i++) {
		c += z[i];
		if (!c)
			v.push_back(i);
	}
	cout << v.size() << '\n';
	for (int x : v)
		cout << x << ' ';
	cout << '\n';
}