#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <cassert>
#include <map>
#include <unordered_map>
 
 
using namespace std;
 
 
#define ll long long
#define ld long double
#define pb push_back
#define emb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
 
const int mxk = 10;
 
 
struct arr {
    array<int, mxk> a;
    int w;
};
 
 
bool operator<(const arr& a1, const arr& a2) {
    return a1.w < a2.w;
}
 
 
struct node {
    map<int, int> go;
    int cnt;
 
    void clear() {
        cnt = 0;
        go.clear();
    }
};
 
 
int n, k;
vector<arr> a;
int gsz;
vector<node> g;
 
 
int new_node() {
    g[gsz].clear();
    gsz += 1;
    return gsz - 1;
}
 
 
int build() {
    gsz = 0;
    g.resize(n * (1 << k) + 1);
    return new_node();
}
 
 
inline int go(int v, int c) {
    if (g[v].go.find(c) == g[v].go.end()) {
        return (g[v].go[c] = new_node());
    }
    return g[v].go[c];
}
 
 
void add_to_g(const array<int, mxk>& x, int c, int v, int i) {
    if (i == k) {
        g[v].cnt += c;
        return;
    }
    add_to_g(x, c, v, i + 1);
    add_to_g(x, c, go(v, x[i]), i + 1);
}
 
 
void add_to_g(const array<int, mxk>& x, int c) {
    add_to_g(x, c, 0, 0);
}
 
 
inline void add_to_g(const arr &x, int c) {
    return add_to_g(x.a, c);
}
 
 
int get_cnt(const array<int, mxk> &x, int v, int i) {
    if (i == k) {
        return g[v].cnt;
    }
    int res = get_cnt(x, v, i + 1);
    if (g[v].go.find(x[i]) != g[v].go.end()) {
        res -= get_cnt(x, g[v].go[x[i]], i + 1);
    }
    return res;
}
 
 
int get_cnt(const array<int, mxk> &x) {
    return get_cnt(x, 0, 0);
}
 
 
inline int get_cnt(const arr& x){
    return get_cnt(x.a);
}
 
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i].a[j];
        }
        cin >> a[i].w;
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        sort(a[i].a.begin(), a[i].a.begin() + k);
    }
    build();
    int res = -1;
    int i = 0;
    while (i < n && get_cnt(a[i]) == 0) {
        add_to_g(a[i], 1);
        i += 1;
    }
    if (i >= n) {
        cout << -1 << "\n";
        return 0;
    }
    int j = i;
    while (get_cnt(a[i]) != 0) {
        j -= 1;
        add_to_g(a[j], -1);
    }
    res = a[i].w + a[j].w;
    for (i += 1; i < n && j > 0; ++i) {
        while (get_cnt(a[i]) != 0) {
            j -= 1;
            add_to_g(a[j], -1);
        }
        res = min(res, a[i].w + a[j].w);
    }
    cout << res << "\n";
    return 0;
}