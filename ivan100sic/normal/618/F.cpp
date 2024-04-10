#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1000005], b[1000005];
int seen[2000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	int j = 0;
	ll sum = 0;
	vector<pair<int, int>> c;
	for (int i=0; i<n; i++) {
		while (j < n && b[j] <= sum) {
			sum -= b[j];
			c.emplace_back(-b[j], j+1);
			j++;
		}
		sum += a[i];
		c.emplace_back(a[i], i+1);
	}

	while (j < n) {
		sum -= b[j];
		c.emplace_back(-b[j], j+1);
		j++;
	}

	memset(seen, 0xff, sizeof seen);
	sum = 0;
	seen[sum] = 0;
	for (int i=0; i<2*n; i++) {
		sum += c[i].first;
		if (seen[sum] != -1) {
			basic_string<int> x, y;
			for (int j=seen[sum]; j<=i; j++) {
				if (c[j].first > 0)
					x += c[j].second;
				else
					y += c[j].second;
			}
			cout << x.size() << '\n';
			for (int a : x)
				cout << a << ' ';
			cout << '\n' << y.size() << '\n';
			for (int a : y)
				cout << a << ' ';
			cout << '\n';
			return 0;
		} else {
			seen[sum] = i+1;
		}
	}
}