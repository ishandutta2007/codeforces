#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=2*n+1; i++)
		cin >> a[i];

	for (int i=2; i<=2*n; i+=2) {
		if (a[i] > a[i-1] + 1 && a[i] > a[i+1] + 1 && k > 0) {
			k--;
			a[i]--;
		}
	}

	for (int i=1; i<=2*n+1; i++)
		cout << a[i] << ' ';
	cout << '\n';
}