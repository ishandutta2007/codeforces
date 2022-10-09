#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string b, c;
int a[200005], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> b >> c;
	for (int i=0; i<n; i++) {
		a[n-1-i] += b[i] - 'a';
		a[n-1-i] += c[i] - 'a';
	}

	for (int i=n-1; i>=0; i--) {
		if (i)
			a[i-1] += a[i] % 2 * 26;
		a[i] /= 2;
	}

	for (int i=0; i<n; i++) {
		a[i+1] += a[i] / 26;
		a[i] %= 26;
	}

	for (int i=n-1; i>=0; i--)
		cout << char(a[i] + 'a');
	cout << '\n';

}