#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct avion {
	ll v, x; int id;

	ll k() const {
		return x;
	}

	ll b() const {
		return v;
	}
};

ll w;
int n;
avion a[100005];

bool cmp1(avion p, avion q) {
	// (-p.b()-w / p.k()) < (-q.b()-w / q.k())
	bool kontra = (q.k() < 0) ^ (p.k() < 0);
	ll diff = (-p.b()-w) * q.k() - (-q.b()-w) * p.k();
	if (diff == 0) {
		if (p.k() == q.k())
			return false;
		return (p.k() < q.k()) ^ kontra;
	} else {
		return (diff < 0) ^ kontra;
	}
}

bool cmp2(avion p, avion q) {
	// (-p.b()-w / p.k()) < (-q.b()-w / q.k())
	bool kontra = (q.k() < 0) ^ (p.k() < 0);
	ll diff = (-p.b()+w) * q.k() - (-q.b()+w) * p.k();
	if (diff == 0) {
		if (p.k() == q.k())
			return false;
		return (p.k() > q.k()) ^ kontra;
	} else {
		return (diff < 0) ^ kontra;
	}
}

int f[100005];

void add(int x, int v) {
	for (int y=x; y<100005; y+=y&-y)
		f[y] += v;
}

int get(int x) {
	int v = 0;
	for (int y=x; y; y-=y&-y)
		v += f[y];
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].v;
	sort(a, a+n, cmp1);
	for (int i=0; i<n; i++)
		a[i].id = i+1;
	sort(a, a+n, cmp2);
	ll sol = 0;
	for (int i=n-1; i>=0; i--) {
		sol += get(a[i].id);
		add(a[i].id, 1);
	}
	cout << sol << '\n';
}