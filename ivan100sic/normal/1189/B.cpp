#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	if (a[0] >= a[1] + a[2]) {
		cout << "NO\n";
		return 0;
	}
	for (int i=0, x=(n-1)/2, d=1; i<n; i++, x+=d, d=d>0?-d-1:-d+1)
		b[x] = a[i];
	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << b[i] << " \n"[i==n-1];
}