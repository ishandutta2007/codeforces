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

const int maxn = 1 << 19;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
int l[maxn], v[maxn], r[maxn];
vector<int> e[maxn], g[maxn];
int t[2 * maxn], a[2 * maxn];

void push(int v, int tl, int tr) {
    if (a[v]) {
        t[v] += a[v];
        if (tl != tr) a[v * 2] += a[v];
        if (tl != tr) a[v * 2 + 1] += a[v];
        a[v] = 0;
    }
}

void add(int v, int tl, int tr, int l, int r, int d) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
        a[v] += d;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    add(v * 2, tl, tm, l, min(r, tm), d);
    add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, d);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) >> 1;
    return get(v * 2, tl, tm, l, min(r, tm)) + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int c[maxn];

void restore(int x) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        if (l[i] <= x && x <= v[i]) {
            c[v[i]]++;
            c[r[i] + 1]--;
        }
    }
    
    int ans = 0, pans = -1;
    int cur = 0;
    for (int i = x; i < maxn; i++) {
        cur += c[i];
        if (cur > ans) {
            ans = cur;
            pans = i;
        }
    }
    
    vector<int> res;
    for (int i = 0; i < n; i++) if (l[i] <= x && x <= v[i] && v[i] <= pans && pans <= r[i]) res.push_back(i + 1);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " \n"[i + 1 == res.size()];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) scanf("%d%d%d", &l[i], &v[i], &r[i]);
        
        for (int i = 0; i < maxn; i++) e[i].clear(), g[i].clear();
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n; i++) e[l[i]].push_back(i), g[v[i]].push_back(i);
        
        int ans = 0, pans = -1;
        for (int i = maxn - 1; i >= 0; i--) {
            for (int j = 0; j < g[i].size(); j++) {
                add(1, 0, maxn - 1, v[g[i][j]], r[g[i][j]], 1);
            }
            int res = t[1];
            if (ans < res) {
                ans = res;
                pans = i;
            }
            for (int j = 0; j < e[i].size(); j++) {
                add(1, 0, maxn - 1, v[e[i][j]], r[e[i][j]], -1);
            }            
        }
        cerr << ans << " " << pans << endl;
        restore(pans);
    }

	return 0;
}