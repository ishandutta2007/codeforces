#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 100500;
int k, n, m;
ll a[N];

struct node {
	double k; ll num, t;
	bool operator < (const node &i) const {
		return k > i.k;
	}
};

struct kick {
	int a, num, t;
	bool operator < (const kick &i) const {
		return a < i.a;
	}
};

#define MP make_pair
vector< kick > add[N];
vector< node > mul;
pair<int, int> tmp[N];

bool cmp(node i, node j) { return i.t > j.t; }

int main() {
	read(k), read(n), read(m);
	for (int i = 1;i <= k; i++) read(a[i]);
	for (int i = 1;i <= n; i++) {
		int opt, x, y; read(opt), read(x), read(y);
		if (opt == 1) {
			pair<int, int> t = MP(y - a[x], i);
			if (t > tmp[x]) tmp[x] = t;
		}
		else if (opt == 2) add[x].push_back((kick){y, i, 2});
		else mul.push_back((node){(double)y, i, 3});
	}
	
	for (int i = 1;i <= k; i++) {
		if (tmp[i].first > 0) add[i].push_back((kick){tmp[i].first, tmp[i].second, 1});
		sort(add[i].begin(), add[i].end());
		for (int j = add[i].size() - 1; j >= 0; j--)
			mul.push_back((node){(double)(a[i] + add[i][j].a) /a[i], add[i][j].num, add[i][j].t}), a[i] += add[i][j].a;
	}
	
	m = min(m, (int)mul.size());
	sort(mul.begin(), mul.end());
	for (int i = m - 1;i >= 0; i--) if (mul[i].k > 1) {	m = i + 1; break; }
	printf ("%d\n", m); sort(mul.begin(), mul.begin() + m, cmp);
	for (int i = m - 1;i >= 0; i--) printf ("%lld ", mul[i].num);
	return 0;
}