#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int j=0; j<m; j++)
		cin >> b[j];
	sort(a, a+n);
	sort(b, b+m);

	if (a[n-1] > b[0]) {
		cout << "-1\n";
		return 0;
	}

	ll sum = accumulate(a, a+n, 0ll) * m;
	int pos = n-1, rem = m-1;
	for (int j=0; j<m; j++) {
		if (b[j] == a[n-1])
			continue;
		if (rem == 0)
			pos--, rem = m-1;
		// cerr << "pv: " << pos << ' ' << a[pos] << '\n';
		sum += b[j] - a[pos];
		rem--;
	}

	cout << sum << '\n';
}

/*

  0 1
1 0 1
1 0 1
2 0 1

*/