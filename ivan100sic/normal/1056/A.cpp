#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1011];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			a[y]++;
		}
	}
	for (int i=1; i<=100; i++)
		if (a[i] == n)
			cout << i << ' ';
	cout << '\n';

}