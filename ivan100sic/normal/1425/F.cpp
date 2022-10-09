// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int ask(int l, int r) {
	cout << "? " << l << ' ' << r << '\n' << flush;
	int x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;

	vector<int> a(n+1);
	int s123 = ask(1, 3);
	int s12 = ask(1, 2);
	int s23 = ask(2, 3);
	a[2] = s12 + s23 - s123;
	a[1] = s12 - a[2];
	a[3] = s23 - a[2];
	for (int i=4; i<=n; i++) {
		int x = ask(i-1, i);
		a[i] = x - a[i-1];
	}

	cout << '!';
	for (int i=1; i<=n; i++) {
		cout << ' ' << a[i];
	}
	cout << '\n';

}