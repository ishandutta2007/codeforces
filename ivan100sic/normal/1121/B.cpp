#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<int, int> sz;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			sz[a[i] + a[j]]++;
	int z=0;
	for (auto [x, y] : sz)
		z = max(z, y);
	cout << z << '\n';
}