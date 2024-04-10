#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
basic_string<int> e[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=2*n; i++) {
		cin >> a[i];
		e[a[i]] += i;
	}
	int x = 1, y = 1;
	ll z = 0;
	for (int i=1; i<=n; i++) {
		int p = e[i][0];
		int q = e[i][1];
		z += min(abs(x-p)+abs(y-q), abs(x-q)+abs(y-p));
		x = p;
		y = q;
	}
	cout << z << '\n';
}