#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("unroll-loops")
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 2e5 + 22;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = (ll) 1e18 + 5;
const int inf = 2e9 + 5;

vector<int> crd[maxn];

vector<int> tree[maxn * 4];

int k;
vector<int> mx(const vector<int>& a, const vector<int>& b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    vector<int> c(1 << k);
    for (int i = 0; i < (1 << k); i++)
        c[i] = max(a[i], b[i]);
    // cout << k << endl;
    return c;
}

void upd(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        // cout << "kek";
        tree[v] = vector<int>(1 << k);
        for (int i = 0; i < (1 << k); i++) {
            tree[v][i] = 0;
            for (int j = 0; j < k; j++)
                if (i & (1 << j))
                    tree[v][i] += crd[tl][j];
                else
                    tree[v][i] -= crd[tl][j];
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        upd(v<<1, tl, tm, pos);
    else
        upd(v<<1|1, tm + 1, tr, pos);
    tree[v] = mx(tree[v<<1], tree[v<<1|1]);
}

vector<int> get(int v, int tl, int tr, int l, int r) {
    if (l > r) return vector<int>(1 << k, -inf);
    if (tl  == l && tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return mx(
        get(v<<1, tl, tm, l, min(r, tm)),
        get(v<<1|1, tm + 1, tr, max(l, tm + 1), r)
    );
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        crd[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> crd[i][j];
        }
        upd(1, 0, n - 1, i);
    }

    // exit(0);

    int q;
    cin >> q;

    while (q--){
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i--;

            for (int j = 0; j < k; j++)
                cin >> crd[i][j];

            upd(1, 0, n - 1, i);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;

            vector<int> gt = get(1, 0, n - 1, l, r);
            int re = 0;
            for (int i = 0; i < (1 << k); i++)
                re = max(re, gt[i] + gt[((1 << k) - 1) ^ i]);
            cout << re << "\n";
        }
    }
    return 0;
}