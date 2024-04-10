#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")


const int maxn = 1 << 17;

struct my {
	int a[26];
	
	my() {}
	my(int x) {
		if (x == -1)
			memset(a, 255, sizeof(a));
		else
			memset(a, 0, sizeof(a));
	}

	my operator + (const my &c) {
		my res(0);
		for (int i = 0; i < 26; i++)
			res.a[i] = a[i] + c.a[i];
		return res;
	}
};
 
int n, m;
string s;
my t[4 * maxn], T[4 * maxn], nill = my(0);

void push(int v, int l, int r, int x = -1) {
	for (int i = (x == -1 ? 0 : x); i < (x == -1 ? 26 : x+1); i++) if (T[v].a[i]) {
		if (l != r) T[v*2].a[i] = T[v].a[i];
		if (l != r) T[v*2+1].a[i] = T[v].a[i];
		t[v].a[i] = max(0, T[v].a[i]) * (r - l + 1);
		T[v].a[i] = 0;
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].a[s[tl]-'a'] = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

my get(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return nill;
	push(v, tl, tr);
	if (tl == l && tr == r) {
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	my res = get(v * 2, tl, tm, l, min(r, tm)) + 
		get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return res;
}

void upd(int v, int tl, int tr, int l, int r, int x, int y) {
	push(v, tl, tr, x);
	if (l > r) return;
	if (tl == l && tr == r) {
		T[v].a[x] = y == 1 ? 1 : -1;
		push(v, tl, tr, x);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, tl, tm, l, min(r, tm), x, y);
	upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x, y);
	t[v].a[x] = t[v*2].a[x] + t[v*2+1].a[x];
}

void Upd(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > r) return;
	if (tl == l && tr == r) {
		T[v] = my(-1);
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	Upd(v * 2, tl, tm, l, min(r, tm));
	Upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	t[v] = t[v*2] + t[v*2+1];
}

void print(int v, int tl, int tr) {
	push(v, tl, tr);
	if (tl == tr) {
		for (int i = 0; i < 26; i++)
			if (t[v].a[i])
				cout << (char)('a' + i);
		return;
	}
	int tm = (tl + tr) >> 1;
	print(v * 2, tl, tm);
	print(v * 2 + 1, tm  +1, tr);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	cin >> n >> m >> s;
	build(1, 0, n-1);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		my a = get(1, 0, n-1, l-1, r-1);
		int can = 0;
		for (int i = 0; i < 26; i++)
			can += a.a[i] % 2;
		if (can > 1)
			continue;
		//for (int i = 0; i < 26; i++)
		//	upd(1, 0, n-1, l-1, r-1, i, 0);
		Upd(1, 0, n-1, l-1, r-1);
		int curl = l-1, curr = r-1;
		for (int i = 0; i < 26; i++) {
			if (a.a[i] % 2 == 1) {
				upd(1, 0, n-1, (curl + curr) / 2, (curl + curr) / 2, i, 1);
			}
			upd(1, 0, n-1, curl, curl + a.a[i]/2 - 1, i, 1);
			upd(1, 0, n-1, curr - a.a[i]/2 + 1, curr, i, 1);
			curl += a.a[i]/2;
			curr -= a.a[i]/2;
		}
	}

	print(1, 0, n-1);

	return 0;
}