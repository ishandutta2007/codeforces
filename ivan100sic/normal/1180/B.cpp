#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> c[1000005];
int a[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] >= 0)
			a[i] = -a[i]-1;
	}

	if (n % 2) {
		int& x = *min_element(a, a+n);
		x = -x-1;		
	}

	for (int i=0; i<n; i++)
		cout << a[i] << " \n"[i == n-1];
}