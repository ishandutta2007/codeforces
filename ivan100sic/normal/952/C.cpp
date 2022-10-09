#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105], b[105];

bool check(int* a, int* b) {
	int m = b - a;
	for (int i=1; i<m; i++)
		if (abs(a[i] - a[i-1]) > 1)
			return false;
	return true;
}

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=n; i>=1; i--) { // velicina ostatka niza
		if (!check(a, a+i))
			no();

		int k = 0;
		for (int j=0; j<i; j++)
			if (a[j] > a[k])
				k = j;

		rotate(a+k, a+k+1, a+i);
		b[i-1] = a[i-1];
		if (!check(b+i-1, b+n))
			no();
	}

	cout << "YES\n";
}