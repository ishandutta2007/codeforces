//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

struct Item {
    int w, h, id;
    Item() {}
    Item(int w, int h, int id) : w(w), h(h), id(id) {}
};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Item> a(n);
        vector<int> kek;
        for (int i = 0; i < n; i++) {
            int w, h;
            cin >> w >> h;
            a[i] = Item(w, h, i);
            kek.push_back(w);
            kek.push_back(h);
        }
        sort(all(kek));
        kek.erase(unique(all(kek)), kek.end());
        map<int, int> f;
        for (int i = 0; i < kek.size(); i++)
            f[kek[i]] = i;
        for (int i = 0; i < n; i++) {
            a[i].w = f[a[i].w];
            a[i].h = f[a[i].h];
        }
        vector<vector<Item>> tmp(2 * n);
        for (int i = 0; i < n; i++) {
            tmp[a[i].w].push_back(a[i]);
            if (a[i].w != a[i].h)
                tmp[a[i].h].push_back(a[i]);
        }
        ll mn = inf0, id = -1;
        vector<int> ans(n, -2);
        for (int i = 0; i < 2 * n; i++) {
            for (auto u : tmp[i]) {
                if (u.w == i) {
                    if (mn < u.h)
                        ans[u.id] = id;
                } else {
                    if (mn < u.w)
                        ans[u.id] = id;
                }
            }
            for (auto u : tmp[i]) {
                if (u.w == i) {
                    if (mn > u.h) {
                        mn = u.h;
                        id = u.id;
                    }
                } else {
                    if (mn > u.w) {
                        mn = u.w;
                        id = u.id;
                    }
                }
            }
        }
        for (int i : ans)
            cout << i + 1 << " ";
        cout << endl;
    }
    return;
}