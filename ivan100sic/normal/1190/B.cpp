#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int solve(vector<int> a) {
	int n = a.size();
	if (n == 1)
		return a[0] % 2;
	map<int, int> mp;
	for (int x : a)
		mp[x]++;
	int c2=0, c3=0, p2;
	for (auto [x, y] : mp) {
		if (y == 2)
			c2++, p2 = x;
		else if (y > 2)
			c3++;
	}
	if (c3 > 0 || c2 > 1)
		return 2; // nema ti spasa
	if (c2 == 1) {
		if (p2 == 0)
			return 4;
		--*find(a.begin(), a.end(), p2);
		sort(a.begin(), a.end());
		for (int i=1; i<n; i++)
			if (a[i] == a[i-1])
				return 6;
		// normalna igra do 0,1,2,3...
		return 8 + (accumulate(a.begin(), a.end(), 0ll) - n*(n-1ll)/2 + 1)%2;
	} else {
		return 10 + (accumulate(a.begin(), a.end(), 0ll) - n*(n-1ll)/2)%2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	cout << "cslnb\0sjfnb\0"+(solve(a)%2*6) << '\n';
}