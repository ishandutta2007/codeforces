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
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
int a[maxn];
int t1[2 * maxn];
ll t2[2 * maxn];

void build1(int v, int tl, int tr) {
    if (tl == tr) {
        t1[v] = tl;
        return;
    }
    int tm = (tl + tr) >> 1;
    build1(v * 2, tl, tm);
    build1(v * 2 + 1, tm + 1, tr);
    t1[v] = a[t1[v * 2]] >= a[t1[v * 2 + 1]] ? t1[v * 2] : t1[v * 2 + 1];
}

void build2(int v, int tl, int tr) {
    if (tl == tr) {
        t2[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build2(v * 2, tl, tm);
    build2(v * 2 + 1, tm + 1, tr);
    t2[v] = t2[v * 2] + t2[v * 2 + 1];
}

int get1(int v, int tl, int tr, int l, int r) {
    if (l > r) return n;
    if (l == tl && r == tr) return t1[v];
    int tm = (tl + tr) >> 1;
    int res1 = get1(v * 2, tl, tm, l, min(r, tm));
    int res2 = get1(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return a[res1] >= a[res2] ? res1 : res2;
}

ll get2(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t2[v];
    int tm = (tl + tr) >> 1;
    ll res1 = get2(v * 2, tl, tm, l, min(r, tm));
    ll res2 = get2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return res1 + res2;
}

void upd1(int v, int tl, int tr, int x) {
    if (tl == tr) {
        return;
    }
    int tm = (tl + tr) >> 1;
    if (x <= tm) upd1(v * 2, tl, tm, x);
    else upd1(v * 2 + 1, tm + 1, tr, x);
    t1[v] = a[t1[v * 2]] >= a[t1[v * 2 + 1]] ? t1[v * 2] : t1[v * 2 + 1];
}

void upd2(int v, int tl, int tr, int x) {
    if (tl == tr) {
        t2[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    if (x <= tm) upd2(v * 2, tl, tm, x);
    else upd2(v * 2 + 1, tm + 1, tr, x);
    t2[v] = t2[v * 2] + t2[v * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        a[n] = -1;
        build1(1, 0, n - 1);
        build2(1, 0, n - 1);
        
        for (int i = 0; i < m; i++) {
            int t;
            scanf("%d", &t);
            if (t == 1) {
                int l, r;
                scanf("%d%d", &l, &r);
                cout << get2(1, 0, n - 1, l - 1, r - 1) << "\n";
            }
            if (t == 2) {
                int l, r, x;
                scanf("%d%d%d", &l, &r, &x);
                while (true) {
                    int mx = get1(1, 0, n - 1, l - 1, r - 1);
                    if (a[mx] >= x) {
                        a[mx] %= x;
                        upd1(1, 0, n - 1, mx);
                        upd2(1, 0, n - 1, mx);
                    } else break;
                }
            }
            if (t == 3) {
                int k, x;
                scanf("%d%d", &k, &x);
                a[k - 1] = x;
                upd1(1, 0, n - 1, k - 1);
                upd2(1, 0, n - 1, k - 1);
            }
        }
    }

	return 0;
}