#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ordered_set = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1 << 18;

ordered_set st[2 * N];
int p[N];
struct Tree {
    int n;
    ll ans;

    Tree () {}

    Tree (int _n) {
        n = _n;
        ans = 0;
        forn(i, 0, n) p[i] = i;
        forn(i, 0, n) add(i, i);
    }
    
    void add(int pos, int val) {
        pos += N;
        while (pos) {
            st[pos].insert(val);
            pos /= 2;
        }
    }

    void rem(int pos, int val) {
        pos += N;
        while (pos) {
            st[pos].erase(val);
            pos /= 2;
        }
    }

    int less_left(int pos) {
        int val = p[pos];
        int rez = 0;
        pos += N;
        while (pos) {
            if (pos % 2) rez += (int)st[pos - 1].order_of_key(val);
            pos /= 2;
        }
        return rez;
    }

    int inv(int pos) {
        int x = less_left(pos);
        return (pos - x) + (p[pos] - x);
    }

    void Swap(int i, int j) {
        if (i == j) return;
        if (i > j) swap(i, j);
        ans -= inv(i);
        ans -= inv(j);
        if (p[i] > p[j]) ++ans;
        rem(i, p[i]);
        rem(j, p[j]);
        swap(p[i], p[j]);
        add(i, p[i]);
        add(j, p[j]);
        ans += inv(i);
        ans += inv(j);
        if (p[i] > p[j]) --ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    Tree T(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        T.Swap(l, r);
        cout << T.ans << '\n';
    }
}