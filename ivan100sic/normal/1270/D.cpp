#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	map<int, int> a;
	for (int i=0; i<k+1; i++) {
		cout << "?";
		for (int j=0; j<k; j++)
			cout << ' ' << (i+j)%(k+1) + 1;
		cout << '\n' << flush;
		int x, y;
		cin >> x >> y;
		a[y]++;
	}
	cout << "! " << a.rbegin()->second << '\n' << flush;
}