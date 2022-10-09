#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<int, int> a;
	int z=0;
	for (int x : {1,1,1,1,1}) {
		cin >> x;
		a[x]++;
		z+=x;
	}
	int y=0;
	for (auto p : a) {
		if (p.second > 1)
			y = max(y, p.first * min(p.second, 3));
	}
	cout << z - y;
}