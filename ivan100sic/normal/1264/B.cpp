#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[4];
int b[100005], e;

void probaj1(int x) {
	int a[4];
	copy(c, c+4, a);
	int n = accumulate(a, a+4, 0);
	e = 0;

	while (1) {
		b[e++] = x;
		a[x]--;
		if (e == n)
			break;
		if (x > 0 && a[x-1] > 0)
			x--;
		else if (x < 3 && a[x+1] > 0)
			x++;
		else
			return;
	}

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << b[i] << " \n"[i == n-1];
	exit(0);
}

void probaj2(int x) {
	int a[4];
	copy(c, c+4, a);
	int n = accumulate(a, a+4, 0);
	e = 0;
	
	while (1) {
		b[e++] = x;
		a[x]--;
		if (e == n)
			break;
		if (x < 3 && a[x+1] > 0)
			x++;
		else if (x > 0 && a[x-1] > 0)
			x--;
		else
			return;
	}

	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << b[i] << " \n"[i == n-1];
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> c[0] >> c[1] >> c[2] >> c[3];

	for (int x=0; x<4; x++) {
		if (c[x] > 0) {
			probaj1(x);
			probaj2(x);
		}
	}
	cout << "NO\n";
}