#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
map<int, basic_string<int>> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		mp[x] += i;
	}

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		mp[x] += i;
	}

	cin >> m;

	ll z = 1, p2 = 0;

	for (auto [ignore, v] : mp) {
		sort(v.begin(), v.end());
		int twins = 0;
		for (int i=0; i<(int)v.size()-1; i++)
			if (v[i] == v[i+1])
				twins++;
		for (int i=1; i<=(int)v.size(); i++) {
			int x = i;
			while (x % 2 == 0)
				x /= 2, p2++;
			z = z * x % m;
		}
		p2 -= twins;
	}
	while (p2--)
		z = 2*z % m;
	cout << z << '\n';
}