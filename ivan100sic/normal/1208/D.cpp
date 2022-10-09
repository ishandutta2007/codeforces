#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct elem {
	ll x;
	int id;

	bool operator< (const elem& b) const {
		if (x == b.x)
			return id > b.id;
		return x < b.x;
	}
};

const int maxn = 262144;
const ll inf = 1e18;

struct lazyseg {
	vector<elem> a;
	vector<ll> b;

	lazyseg() : a(2*maxn), b(2*maxn) {
		for (int i=0; i<maxn; i++)
			a[i+maxn] = {inf, i};
		for (int i=maxn-1; i; i--)
			a[i] = min(a[2*i], a[2*i+1]);
	}

	void push(int x) {
		if (!b[x])
			return;
		a[x].x += b[x];
		if (x < maxn) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		b[x] = 0;
	}

	void update(int l, int r, ll v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += v;
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = min(a[2*x], a[2*x+1]);
	}

	int get() {
		return a[1].id;
	}
};

int n;
ll a[200005];
int p[200005];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	lazyseg drvo;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		drvo.update(i, i, a[i]-inf);
	}
	for (int i=1; i<=n; i++) {
		int j = drvo.get();
		drvo.update(j, j, inf);
		drvo.update(j+1, n, -i);
		p[j] = i;
	}
	for (int i=1; i<=n; i++)
		cout << p[i] << " \n"[i == n];

}