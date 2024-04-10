#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<ll, int> mp;
int n;
ll sol[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		ll l, r;
		cin >> l >> r;
		mp[l]++;
		mp[r+1]--;
	}

	ll prev = -1;
	int zbir = 0;
	for (auto p : mp) {
		sol[zbir] += p.first - prev;
		zbir += p.second;
		prev = p.first;
	}
	for (int i=1; i<=n; i++)
		cout << sol[i] << ' ';
}