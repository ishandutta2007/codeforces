#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[205];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=2*n; i++) {
		cin >> a[i];
	}

	int c = 0;

	for (int i=1; i<=2*n; i+=2) {
		int j = find(a+i+1, a+n+n+1, a[i]) - a;
		while (j-i > 1) {
			swap(a[j], a[j-1]);
			j--;
			c++;
		}
	}

	cout << c << '\n';
}