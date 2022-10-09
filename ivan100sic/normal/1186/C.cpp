#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a, b;
int z[1000005], n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b;
	n = a.size();
	m = b.size();
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + a[i] - '0';
	int bb = accumulate(b.begin(), b.end(), 0), u=0;
	for (int i=0; i<=n-m; i++)
		if (!((z[i] + z[i+m] + bb) & 1))
			u++;
	cout << u << '\n';
}