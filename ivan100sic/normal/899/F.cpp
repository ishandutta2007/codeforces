#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int b[262144];

void fadd(int x, int y) {
	while (x < 262144) {
		b[x] += y;
		x += x & -x;
	}
}

int fget(int x) {
	int y = 0;
	while (x > 0) {
		y += b[x];
		x -= x & -x;
	}
	return y;
}

int fseek(int y) {
	int x = 0;
	for (int i=131072; i>0; i>>=1) {
		if (y >= b[x + i]) {
			y -= b[x + i];
			x += i;
		}
	}
	return x;
}

int kth(int x) {
	return fseek(x-1) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	string s;
	cin >> n >> q >> s;
	map<char, set<int>> e;
	for (int i=0; i<n; i++) {
		e[s[i]].insert(i+1);
	}
	for (int i=1; i<=n; i++)
		fadd(i, 1);
	while (q--) {
		int l, r;
		char c;
		cin >> l >> r >> c;
		int a = kth(l);
		int b = kth(r);

		while (1) {
			auto it = e[c].lower_bound(a);
			if (it == e[c].end() || *it > b)
				break;
			fadd(*it, -1);
			e[c].erase(it);
		}
	}
	int len = fget(n);
	for (int i=1; i<=len; i++) {
		cerr << "kth " << kth(i) << '\n';
		cout << s[kth(i)-1];
	}
	cout << '\n';
}