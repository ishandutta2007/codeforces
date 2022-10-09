#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[321321];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<2*n; i++)
		cin >> a[i];
	if (count(a, a+2*n, a[0]) == 2*n) {
		cout << "-1\n";
	} else {
		sort(a, a+2*n);
		for (int i=0; i<2*n; i++)
			cout << a[i] << ' ';
	}
}