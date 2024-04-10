#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) {
        ris << "(" << r.first << ", " << r.second << ")";
    }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

vector<int> v[1000007];
int dp_wl[1000007];
int dp_nwl[1000007];

void dfs(int x, int oj) {
    dp_wl[x] = 1;
    dp_nwl[x] = 0;
    int synowie = 0;
    for (auto it : v[x]) {
        if (it != oj) {
            dfs(it, x);
            synowie++;
        }
    }
    for (auto it : v[x]) {
        if (it != oj) {
            dp_wl[x] = max(dp_wl[x], dp_nwl[it] + 1);
            dp_nwl[x] = max(max(dp_wl[it], dp_nwl[it]) + synowie - 1, dp_nwl[x]);
        }
    }
    debug << arr(dp_wl, x) << arr(dp_nwl, x);
}

int maxi = 0;

void dfs2(int x, int oj) {
    int rdp_wl = dp_wl[x], rdp_nwl = dp_nwl[x];
    vector<pair<int, int>> kandydaci;
    int synowie = v[x].size();
    vector<pair<int, int>> dp_wl_naj;
    vector<pair<int, int>> dp_nwl_naj;
    for (auto it : v[x]) {
        dp_wl_naj.push_back({dp_nwl[it], it});
        dp_nwl_naj.push_back({max(dp_wl[it], dp_nwl[it]), it});
    }
    sort(dp_wl_naj.begin(), dp_wl_naj.end(), greater<pii>());
    sort(dp_nwl_naj.begin(), dp_nwl_naj.end(), greater<pii>());
    int serio_dp_wl = max(1, dp_wl_naj[0].first + 1);
    int serio_dp_nwl = dp_nwl_naj[0].first + synowie - 1;
    maxi = max(maxi, max(serio_dp_wl, serio_dp_nwl));
    for (auto it : v[x]) {
        if (it != oj) {
            int wl_naj = dp_wl_naj[0].first;
            if (dp_wl_naj[0].second == it && synowie != 1)
                wl_naj = dp_wl_naj[1].first;
            else if (dp_wl_naj[0].second == it)
                wl_naj = 0;
            int nwl_naj = dp_nwl_naj[0].first;
            if (dp_nwl_naj[0].second == it && synowie != 1)
                nwl_naj = dp_nwl_naj[1].first;
            else if (dp_nwl_naj[0].second == it)
                nwl_naj = 0;
            dp_wl[x] = max(1, wl_naj + 1);
            dp_nwl[x] = nwl_naj + max(0, synowie - 2);
            dfs2(it, x);
        }
    }
    dp_wl[x] = rdp_wl;
    dp_nwl[x] = rdp_nwl;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1);
    dfs2(1, -1);
    printf("%d\n", maxi);
    return 0;
}