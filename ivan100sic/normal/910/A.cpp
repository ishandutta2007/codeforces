#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x;
string s;
int d[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	cin >> s;
	fill(d, d+105, 123123123);
	d[0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=1; j<=x && i+j < n; j++) {
			if (s[i+j] == '1')
				d[i+j] = min(d[i+j], d[i] + 1);
		}
	}
	int z = d[n-1];
	if (z == 123123123)
		z = -1;
	cout << z << '\n';
}