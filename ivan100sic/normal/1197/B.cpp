#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005], b[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n-1; i++)
		b[i] = a[i] < a[i+1];
	reverse(b, b+n-1);
	cout << (is_sorted(b, b+n-1) ? "YES\n" : "NO\n");
}