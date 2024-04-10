#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

int resi(vector<int> a, int d) {
	if (d == -1 || a.size() == 0)
		return 0;
	vector<int> b, c;
	for (int x : a)
		if (x & (1 << d))
			b.push_back(x);
		else
			c.push_back(x);
	if (b.size() == 0 || c.size() == 0)
		return max(resi(b, d-1), resi(c, d-1));
	else
		return (1 << d) + min(resi(b, d-1), resi(c, d-1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cout << resi(vector<int>(a, a+n), 29) << '\n';
}