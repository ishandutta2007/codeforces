#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];
int m;
int b[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> m;
	for (int i=0; i<m; i++)
		cin >> b[i];
	cout << *max_element(a, a+n) << ' ' << *max_element(b, b+m) << '\n';
}