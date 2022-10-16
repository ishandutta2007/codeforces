//
//  main.cpp
//  Work in Moscow
//
//  Created by Ivan Gorbunov on 21.07.17.
//  Copyright  2017 Ivan Gorbunov. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

//#define int long long

long long gcd(long long a, long long b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

long long NOK(long long a, long long b) {
    return a * b / gcd(a, b);
}

pair<long long, long long> solve(long long n, long long k, long long a, long long b) {
    long long s = a;
    long long l = (b - a + k + k + k + k + k) % k;
    long long min1 = 100000000000LL;
    long long max1 = -1000000LL;
    long long size1 = n * k;
    if (a == k || b == k) {
        return make_pair(min1, max1);
    }
    for (; l < n * k; l += k) {
        long long now;
        //cout << n * k << " " << l << endl;
        if (l == 0LL) {
            now = 1LL;
        } else {
            now = n * k / gcd(size1, l);
        }
        if (now < min1) {
            min1 = now;
        }
        if (now > max1) {
            max1 = now;
        }
    }
    return make_pair(min1, max1);
}

vector<bool> used3(200000, false);
int t[800000];

int nod(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a > b) {
        return nod(a - b, b);
    } else {
        return nod(a, b - a);
    }
}


void build (vector<int> &a, int v, int l, int r) {
    if (l == r - 1) {
        t[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build (a, v * 2 + 1, l, m);
        build (a, v * 2 + 2, m, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

void update (int v, int l, int r, int pos, int new_val) {
    if (l == r - 1)
        t[v] = new_val;
    else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update (v * 2 + 1, l, m, pos, new_val);
        } else {
            update (v * 2 + 2, m, r, pos, new_val);
        }
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
}

int all_sum (int v, int l, int r, int vl, int vr) {
    if (l >= r) {
        return 1000000;
    }
    if (l == vl && r == vr) {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    int sum1 = all_sum(v * 2 + 1, l, min(r, vm), vl, vm);
    int sum2 = all_sum(v * 2 + 2, max(l, vm), r, vm, vr);
    return min(sum1, sum2);
}

vector<int> g[200000];
vector<bool> used(200000, false);

vector<int> now5;
bool flag = true;
int n;

vector<vector<int>> next2(200000, vector<int> (20, 10000000));

void dfs(int v) {
    used[v] = true;
    now5.push_back(v);
    int last = -1;
    for (auto u: g[v]) {
        if (!used[u])
            dfs(u);
        last = u;
    }
    if (last == -1) {
        return;
    }
    //cout << v << endl << endl;
    next2[v][0] = last;
    //cout << last << endl;
    for (int i = 1; i < 20; i++) {
        if (next2[v][i - 1] == 10000000) {
            next2[v][i] = 10000000;
            //cout << next2[v][i] << endl;
            continue;
        }
        next2[v][i] = next2[next2[v][i - 1]][i - 1];
    }
}

int get(int v) {
    int now = 0;
    for (int i = 20; i >= 0; i--) {
        if (now + (1 << i) <= n - 1) {
            now += (1 << i);
            v = next2[v][i];
            if (v == 10000000) {
                return 10000000;
            }
        }
    }
    return v;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, q;
    cin >> n >> m >> q;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        arr1[c - 1] = i;
    }
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        c--;
        arr[i] = arr1[c];
        //cout << arr[i] << " ";
    }
    //cout << endl;
    vector<int> now(m);
    vector<int> last(n, -1);
    vector<bool> check2(m);
    //return 0;
    for (int i = m - 1; i >= 0; i--) {
        int next = arr[i] + 1;
        next %= n;
        int ind = last[next];
        if (ind == -1) {
            now[i] = -1;
            last[arr[i]] = i;
            continue;
        }
        check2[ind] = true;
        g[i].push_back(last[next]);
        //cout << i << " " << last[next] << " " << next;
        last[arr[i]] = i;
    }
    vector<int> next1(m, 10000000);
    //return 0;
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    //return 0;
    for (int i = 0; i < m; i++) {
        next1[i] = get(i);
        //cout << next1[i] << " ";
    }
    //return 0;
    build(next1, 0, 0, m);
    for (int i = 0; i < q; i++) {
        int l; int r;
        cin >> l >> r;
        l--;
        int min1 = all_sum(0, l, r, 0, m);
        if (min1 < r) {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    return 0;
}