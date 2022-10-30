//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;

#define next ajksdslk

int pos[101], h[101], a[101];
int hero[101];
int l[101], r[101];

int dp[101];
int par[101];

bool can(int it_hero, int pos) {
    if (l[it_hero] <= pos && pos <= r[it_hero]) return true;
    return false;
}

bool can2(int it_hero, int pos) {
    return pos == l[it_hero] - 1 || pos == r[it_hero] + 1;
}

int n, m;
void solve(int mid, bool flag) {
    vector<int> exits;
    exits.pb(mid);
    if (!flag) {
        for (int i = mid - 1; i >= 0; i--)
            if (hero[i] != -1)
                exits.pb(i);
    }
    else {
        for (int i = mid + 1; i < n; i++)
            if (hero[i] != -1)
                exits.pb(i);

    }

    int cnt_sleva = exits.size() - 1;
//    for (auto e : exits)
//        cout << e << ' ';
//    cout << endl;
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int cur = 0; cur < exits.size(); cur++) {
        if (dp[cur] == false) continue;
        for (int j = cur + 1; j < exits.size(); j++) {
            if (can(hero[exits[j]], exits[cur])) {
                dp[j] = true;
                par[j] = cur;
            }
        }
    }

    if (!dp[exits.size() - 1]) return;

    vector<int> order;

    int cur = exits.size() - 1;
    while (cur != 0) {
        order.pb(hero[exits[cur]]);
        cur = par[cur];
    }
    reverse(all(order));

    exits.clear();
    exits.pb(mid);

    if (flag) {
        for (int i = mid - 1; i >= 0; i--)
            if (hero[i] != -1)
                exits.pb(i);
    } else {
        for (int i = mid + 1; i < n; i++)
            if (hero[i] != -1)
                exits.pb(i);
    }
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int cur = 0; cur < exits.size(); cur++) {
        if (dp[cur] == false) continue;
        for (int j = cur + 1; j < exits.size(); j++) {
            if (can(hero[exits[j]], exits[cur])) {
                dp[j] = true;
                par[j] = cur;
            } else if (cnt_sleva && cur == 0 && can2(hero[exits[j]], mid)) {
                dp[j] = true;
                par[j] = cur;
            }
        }
    }

    if (!dp[exits.size() - 1]) return;

    vector<int> order1;
    cur = exits.size() - 1;
    while (cur != 0) {
        order1.pb(hero[exits[cur]]);
        cur = par[cur];
    }
    reverse(all(order1));

    for (int i = 0; i < order1.size(); i++) {
        order.pb(order1[i]);
    }

    vector<int> used(m);
    for (int i = 0; i < order.size(); i++)
        used[order[i]] = true;

    for (int i = 0; i < m; i++)
        if (!used[i])
            order.pb(i);

    cout << mid + 1 << "\n";
    for (int i : order)
        cout << i + 1 << ' ';
    cout << "\n";
    exit(0);
}

int main() {
//    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    memset(hero, -1, sizeof(hero));

    for (int i = 0; i < m; i++) {
        cin >> pos[i] >> h[i];
        pos[i]--;
        hero[pos[i]] = i;
    }

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++) {
        l[i] = r[i] = pos[i];
        int pos = ::pos[i];
        int hp = h[i];

        while (pos > 0) {
            pos--;
            hp += a[pos];
            if (hp < 0) break;
            l[i] = pos;
        }

        pos = ::pos[i];
        hp = h[i];
        while (pos + 1 < n) {
            pos++;
            hp += a[pos];
            if (hp < 0) break;
            r[i] = pos;
        }
    }

//    solve(5, 0);
//    exit(0);
//    solve(0, 0);
//    exit(0);

    for (int i = 0; i < n; i++)
        solve(i, 0), solve(i, 1);
    cout << -1 << endl;

}