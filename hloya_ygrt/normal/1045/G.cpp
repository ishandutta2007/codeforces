//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
//#define mt make_tuple
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

const int maxn = (int) 1e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;
#define next ajksdslk

int x[maxn], r[maxn], s[maxn];

vector<int> as;
vector<int> tmp[maxn];

int szh(const vector<int>& a, int x) {
    return lower_bound(all(a), x) - a.begin();
}

struct fnw {
    vector<int> t;

    fnw() {
        al = 0;
        t.clear();
    }

    void init(int n) {
        t.resize(n + 1);
        al = 0;
    }

    int al;

    void add(int pos, int val) {
        al += val;
        assert(pos >= 0 && pos < (int)t.size() - 1);
        pos++;
        while (pos < t.size()) {
            t[pos] += val;
            pos += pos & -pos;
        }
    }

    int geq(int r) {
        int ans = al;
        while (r > 0) {
            ans -= t[r];
            r -= r & -r;
        }
        return ans;
    }
} tree[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    set<int> as_set;
    vector<pair<int, int> > ev;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> r[i] >> s[i];
        as.pb(s[i]);
        as_set.insert(s[i]);

        ev.pb(mp(x[i], - i - 1));
        ev.pb(mp(x[i] + r[i], i + 1));
    }

    sort(all(as));
    as.resize(unique(all(as)) - as.begin());

    for (int i = 0; i < n; i++) {
        tmp[szh(as, s[i])].pb(x[i]);
    }

    for (int i = 0; i < maxn; i++) {
        sort(all(tmp[i]));
        tmp[i].resize(unique(all(tmp[i])) - tmp[i].begin());
        
        if (tmp[i].size()) {
            tree[i].init((int)tmp[i].size());
        }
    }
    
    sort(all(ev));

    long long ans = 0;
    for (int i = 0; i < ev.size(); i++) {
        int it = ev[i].second;
        if (it < 0) {
            //add
            it = -it;
            it--;

            for (int j = -k; j <= k; j++) {
                int iq2 = s[it] + j;
                if (as_set.count(iq2)) {
                    int it2 = szh(as, iq2);
                    int it3 = szh(tmp[it2], x[it] - r[it]);
                    ans += tree[it2].geq(it3);
                }
            }

            int it_tmp = szh(as, s[it]);
            int it3 = szh(tmp[it_tmp], x[it]);
            tree[it_tmp].add(it3, 1);
        } else {
            //delete
            it--;

            int it_tmp = szh(as, s[it]);
            int it3 = szh(tmp[it_tmp], x[it]);
            tree[it_tmp].add(it3, -1);
        }
    }

    cout << ans;
    return 0;
}