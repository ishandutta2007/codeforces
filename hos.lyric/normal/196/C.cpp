#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAXN 1510

int sig(Int r) { return (r < 0) ? -1 : +1; }
struct Pt {
	Int x, y;
	int id;
	Pt() {}
	Pt(Int x, Int y) : x(x), y(y) {}
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Int det(const Pt &a) const { return x * a.y - y * a.x; }
};
int sAP(Pt a, Pt b, Pt c) {
	return sig(a.det(c)) - sig(b.det(c)) - sig(a.det(b));
}

Pt O;
bool cmpXY(const Pt &a, const Pt &b) {
	return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y);
}
bool cmpAngle(const Pt &a, const Pt &b) {
	// return (sAP(a - O, b - O, Pt(-1001001001, 1)) < 0);
	return ((a - O).det(b - O) <= 0);
}

int N;
Pt P[MAXN];
int m, ptr[MAXN], next[MAXN * 2], zu[MAXN * 2];
int cnt[MAXN];
int ans[MAXN];

void dfs0(int u, int p) {
	int i, v;
	cnt[u] = 1;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (v == p) continue;
		dfs0(v, u);
		cnt[u] += cnt[v];
	}
}
void dfs1(int u, int p, int a, int b) {
	int i, v;
	sort(P + a, P + b, cmpXY);
	O = P[a];
	ans[O.id] = u;
	sort(P + a + 1, P + b, cmpAngle);
	int c = a + 1;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (v == p) continue;
		dfs1(v, u, c, c + cnt[v]);
		c += cnt[v];
	}
	assert(c == b);
}

int main() {
	int i, u, v;
	
	for (; ~scanf("%d", &N); ) {
		memset(ptr, ~0, N << 2);
		for (i = 0; i < N - 1; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		for (i = 0; i < N; ++i) {
			P[i].x = in();
			P[i].y = in();
			P[i].id = i;
		}
		dfs0(0, -1);
// cout<<"cnt : ";pv(cnt,cnt+N);
		dfs1(0, -1, 0, N);
		for (i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	
	return 0;
}