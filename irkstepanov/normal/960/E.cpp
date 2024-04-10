#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

vector<vector<int> > g;
vector<int> val;
vector<int> odd, even;

void dfs1(int v, int p) {
    odd[v] = even[v] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        ++odd[v];
        dfs1(to, v);
        odd[v] += even[to];
        even[v] += odd[to];
    }
}

int ans = 0;

void dfs2(int v, int p, int p_odd, int p_even) {
    int cnt = 0;
    add(cnt, p_even);

    int tmp = odd[v];
    mul(tmp, p_odd);
    sub(cnt, tmp);

    tmp = even[v];
    mul(tmp, p_even);
    add(cnt, tmp);

    add(cnt, even[v]);

    int sum_odd = 0, sum_even = 0;
    int sons = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        ++sons;
        tmp = sum_odd;
        mul(tmp, even[to] + 1);
        sub(cnt, tmp);

        tmp = sum_even;
        mul(tmp, odd[to]);
        add(cnt, tmp);

        add(sum_odd, even[to] + 1);
        add(sum_even, odd[to]);
    }

    //cout << v << " " << p_odd << " " << p_even << endl;

    mul(cnt, 2);
    mul(cnt, val[v]);
    add(ans, cnt);

    sum_odd -= sons;

    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        int new_odd = p_even + 1;
        int new_even = p_odd;
        new_even += sons - 1;
        new_even += sum_odd - even[to];
        new_odd += sum_even - odd[to];
        dfs2(to, v, new_odd, new_even);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    val.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        if (val[i] < 0) {
            val[i] += mod;
        }
    }

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    odd.resize(n);
    even.resize(n);
    dfs1(0, 0);

    for (int i = 0; i < n; ++i) {
        add(ans, val[i]);
    }

    dfs2(0, 0, 0, 0);

    cout << ans << "\n";

}