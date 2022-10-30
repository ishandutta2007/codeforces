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

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 9;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;
#define next ajksdslk

int p = 41;
int pw[maxn], sp[maxn], suf[maxn];

int binpow(int n, int st) {
    if (st == 0) return 1;
    int ans = (1LL * binpow(n, st>>1));
    ans = (1ll * ans * ans) % base;
    if (st & 1) ans = (1LL * ans * n) % base;
    return ans;
}

int inv(int s) {
    return binpow(pw[s], base - 2);
}

int main() {
//    freopen("kek.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), c(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        c[i] = a[0] + a[i];
        if (c[i] >= m)
            c[i] -= m;

        b[i] = m - a[i];
        if (b[i] == m) b[i] = 0;
    }

    sort(all(a));
    sort(all(b));

    pw[0] = 1;
    sp[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pw[i] = 1ll * pw[i - 1] * p % base;
        sp[i] = (sp[i - 1] + pw[i]) % base;
    }

    int h1 = 0, h2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        h1 += 1ll * a[i] * pw[i] % base;
        h1 %= base;

        h2 += 1ll * b[i] * pw[i] % base;
        h2 %= base;
        suf[i] = h2;
    }

//    for (int i : a)
//        cout << i << ' ';
//    cout << endl;
//    for (int i : b)
//        cout << i << ' ';
//    cout << endl;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int x = c[i];
        int it = (int)(lower_bound(all(b), m - x) - b.begin());
        int cnt_per = n - it;
        int cnt_not_per = it;

//        cout << x << ' ' << cnt_per << ' ' << cnt_not_per << endl;

        int right = suf[it];
        int left = (h2 - right + base) % base;

        left = 1ll * left * pw[cnt_per] % base;

        right = 1ll * right * inv(cnt_not_per) % base;


        right = (1ll * right + 1ll * (cnt_per > 0 ? sp[cnt_per - 1] : 0) * (x - m) % base) % base;
        if (right < 0) right += base;


        left = (1ll * left + 1ll * (sp[n - 1] - (cnt_per > 0 ? sp[cnt_per - 1] : 0)) * x % base) % base;
        if (left < 0) left += base;

        if ((left + right) % base == h1)
            ans.pb(x);
    }
    sort(all(ans));
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << ' ';
    return 0;
//    int mod = 8;
//    set<int> a = {2, 4, 6};
//    set<int> b;
//    for (int i = 0; i < mod; i++) if (!a.count(i)) b.insert(i);
//    set<int> ok;
//    for (int i = 0; i < mod; i++) ok.insert(i);
//    for (int i : a) for (int j : b) if (ok.count((i + j) % mod)) ok.erase((i + j) % mod);
//
//    for (int i : a) {
//        cout << __algo_gcd(i, mod - 1) << ' ';
//    }
//    cout << endl;
//
//    bool mda = false;
//    vector<int> res;
//    for (int i : a) {
//        vector<int> cur;
//        for (int j : a)
//            cur.pb((i + j) % mod);
////        for (int i : cur)
////            cout << i << ' ';
////        cout << endl;
//        sort(all(cur));
//        if (!mda) {
//            res = cur;
//            mda = true;
//        }
//        else {
//            vector<int> kek;
//            set_intersection(all(cur), all(res), back_inserter(kek));
//            res = kek;
//        }
//    }
//    for (int i : res) cout << i << ' ';
//    cout << endl;
//    for (int i : ok) cout << i << ' ';
    return 0;
}



/*
 *
 *
 */