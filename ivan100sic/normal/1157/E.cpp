#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
multiset<int> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		b.insert(x);
	}

	for (int i=0; i<n; i++) {
		int tgt = (n - a[i]) % n;
		auto it = b.lower_bound(tgt);
		if (it == b.end())
			it = b.begin();
		cout << (a[i] + *it) % n << " \n"[i == n-1];
		b.erase(it);
	}
}