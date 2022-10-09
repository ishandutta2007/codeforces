#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100], b[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int x;
	cin >> x;
	while (x--) {
		int y;
		cin >> y;
		a[y] = 1;
	}
	cin >> x;
	while (x--) {
		int y;
		cin >> y;
		b[y] = 1;
	}
	for (int i=0; i<=2000000; i++) {
		a[i % n] = b[i % m] = (a[i % n] | b[i % m]);
	}

	cout << (accumulate(a, a+n, 0) + accumulate(b, b+m, 0) == n+m
		? "Yes\n" : "No\n");
}