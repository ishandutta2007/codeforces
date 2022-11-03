#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

vector<pair<ll,ll>> tr;
int sz = 1;

pair<ll,ll> operator +(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return { a.first + b.first, a.second + b.second };
}

void add(int i, int val) {
    i += sz;
    tr[i].first++;
    tr[i].second += val;
    while (i) {
        i >>= 1;
        tr[i] = tr[i << 1] + tr[i << 1 | 1];
    }
}

ll get(int v, int l, int r, ll k) {
    if (!k)
        return 0;
    if (!tr[v].first)
        return inf;
    if (l == r - 1)
        return tr[v].second;
    int m = (l + r) >> 1;
    if (tr[v << 1].first >= k)
        return get(v << 1, l, m, k);
    else
        return tr[v << 1].second + get(v << 1 | 1, m, r, k - tr[v << 1].first);
}

ll find(int v, int l, int r, ll mx) {
    if (l == r - 1)
        return tr[v].first && mx >= tr[v].second;
    int m = (l + r) >> 1;
    if (tr[v << 1].second >= mx)
        return find(v << 1, l, m, mx);
    else
        return tr[v << 1].first + find(v << 1 | 1, m, r, mx - tr[v << 1].second);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int test;
    cin >> test;
    while (test--){
        int n, m;
        ll t;
        cin >> n >> m >> t;

        tr.clear();
        sz = 1;
        while (sz < n)
            sz <<= 1;
        tr.resize(2 * sz, make_pair(0, 0));
        const int MX = 2e5 + 1;
        map<int,vector<int>> ind;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ind[x].push_back(i);
        }

        int ans = 0, dd = 1;
        for (auto &c : ind) {
            int d = c.first;
            for (int i : c.second)
                add(i, d);

            ll cur = find(1, 0, sz, t / 2);
            cur -= cur % m;

            ll add = get(1, 0, sz, cur);

            ll af = find(1, 0, sz, t - add);
            af = min(af, cur + m);

            if (ans < af)
                ans = af, dd = d;
        }

        cout << ans << ' ' << dd << '\n';
    }



    return 0;
}