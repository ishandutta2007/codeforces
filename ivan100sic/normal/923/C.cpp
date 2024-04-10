#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int nx[2], c;
} a[300000 * 33]; int sz;

void add(int x, int v = 1) {
	int p = 0;
	for (int i=29; i>=0; i--) {
		int& f = a[p].nx[(x >> i) & 1];
		if (!f)
			p = f = ++sz;
		else
			p = f;
		a[p].c += v;
	}
}

int seek(int x) {
	int p = 0;
	int y = 0;
	for (int i=29; i>=0; i--) {
		int pref = a[p].nx[(x >> i) & 1];
		int bck = a[p].nx[1 - ((x >> i) & 1)];
		if (a[pref].c)
			p = pref;
		else {
			p = bck;
			y ^= 1 << i;
		}
	}
	return y;
}

int n;
int b[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> b[i];

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		add(x);
	}

	for (int i=0; i<n; i++) {
		int x = seek(b[i]);
		cout << x << " \n"[i == n-1];
		add(x ^ b[i], -1);
	}
}