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

	int n, d, c=0;
	cin >> n >> d;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	for (int i=0; i<n; i++)
		for (int j=0; j<i; j++)
			if (abs(a[i] - a[j]) <= d)
				c += 2;
	cout << c;
}