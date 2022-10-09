#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005];
int inv[200005];
int taken[200005];
list<int> b;
list<int>::iterator c[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
		b.push_back(a[i]);
		c[a[i]] = prev(b.end());
	}

	int j = 1, f = n;
	while (b.size()) {
		while (taken[f])
			f--;
		auto it = c[f];

		basic_string<int> to_take;

		auto it1 = it;
		for (int i=0; i<k; i++) {
			++it1;
			if (it1 == b.end())
				break;
			to_take += *it1;
		}
		it1 = it;
		for (int i=0; i<k; i++) {
			if (it1 == b.begin())
				break;
			--it1;
			to_take += *it1;
		}
		to_take += *it;

		for (int x : to_take) {
			b.erase(c[x]);
			taken[x] = j;
		}

		j ^= 3;
	}

	for (int i=1; i<=n; i++)
		cout << taken[a[i]];
	cout << '\n';
}