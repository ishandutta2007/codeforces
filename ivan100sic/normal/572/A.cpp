#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, x, y;
int a[100005];
int b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> x >> y;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		cin >> b[i];

	if (a[x-1] < b[m-y])
		cout << "YES\n";
	else
		cout << "NO\n";
}