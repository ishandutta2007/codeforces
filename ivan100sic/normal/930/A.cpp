#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, z;
int d[100005], l[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	l[0] = 1;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		d[i] = d[p] + 1;
		l[d[i]] += 1;
	}
	for (int i=0; i<100005; i++)
		z += l[i] % 2;
	cout << z << '\n';
}