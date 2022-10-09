#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1000005];
int d[1 << 22];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		d[a[i]] = a[i];
	}
	for (int i=0; i<22; i++)
		for (int j=0; j<(1<<22); j++)
			if (!(j & (1 << i)))
				d[j | (1 << i)] = max(d[j | (1 << i)], d[j]);
	for (int i=0; i<n; i++) {
		if (d[0x3fffff ^ a[i]])
			cout << d[0x3fffff ^ a[i]] << ' ';
		else
			cout << "-1 ";
	}
	cout << '\n';

}