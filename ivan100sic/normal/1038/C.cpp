#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005], x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];

	x = y = n;

	sort(a+1, a+n+1);
	sort(b+1, b+n+1);

	ll sk = 0;

	for (int i=1; i<=n; i++) {
		if (x && a[x] > b[y])
			sk += a[x--];
		else
			y--;

		if (y && b[y] > a[x])
			sk -= b[y--];
		else
			x--;
	}

	cout << sk << '\n';
}