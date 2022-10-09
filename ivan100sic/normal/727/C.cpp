#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ask(int i, int j) {
	cout << "? " << i << ' ' << j << '\n' << flush;
	cin >> i;
	return i;
}

int a[5005], n;

void ans() {
	cout << '!';
	for (int i=1; i<=n; i++)
		cout << ' ' << a[i];
	cout << '\n' << flush;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	int x12 = ask(1, 2);
	int x13 = ask(1, 3);
	int x23 = ask(2, 3);
	int x123 = (x12 + x13 + x23) / 2;

	a[1] = x123 - x23;
	a[2] = x123 - x13;
	a[3] = x123 - x12;

	for (int i=4; i<=n; i++)
		a[i] = ask(i, 1) - a[1];

	ans();
}