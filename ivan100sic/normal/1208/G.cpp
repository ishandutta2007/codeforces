#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int e[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "3\n";
		return 0;
	}
	iota(e, e+n+1, 0);
	for (int i=1; i<=n; i++)
		for (int j=2*i; j<=n; j+=i)
			e[j] -= e[i];
	vector<int> q(n-2);
	for (int i=0; i<n-2; i++)
		q[i] = i+3;
	sort(q.begin(), q.end(), [&](int x, int y) { return e[x] < e[y]; });
	q.resize(k);
	ll z = 2;
	for (int x : q)
		z += e[x];
	cout << z << '\n';
}