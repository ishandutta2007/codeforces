#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <algorithm>
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

const int maxn = (int) 1e6 + 25;
const int maxlog = 21;
// const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

vector<int> p = {29, 31};
vector<int> base = {1073676287, (int)1e9 + 9};

string s, t;

int n;

pair<int, int> h[maxn], pw[maxn];

pair<int, int> getHash(int r) {
    return h[r];
}

void sub(int& x, int y, int mod) {
    x -= y;
    if (x < 0)
        x += mod;
}


void add(int& x, int y, int mod) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int mul(int x, int y, int mod) {
    return 1ll * x * y % mod;
}

pair<int, int> mul(const pair<int, int>& h, const pair<int, int>& h2) {
    return mp(mul(h.f, h2.f, base[0]), mul(h.s, h2.s, base[1]));
}

void sub(pair<int, int>& x, const pair<int, int> & y) {
    sub(x.f, y.f, base[0]);
    sub(x.s, y.s, base[1]);
}

void add(pair<int, int>& x, const pair<int, int> & y) {
    add(x.f, y.f, base[0]);
    add(x.s, y.s, base[1]);
}

pair<int, int> getHash(int l, int r) {
    pair<int, int> hr = getHash(r);
    if (l != 0) {
        pair<int, int> hl = getHash(l - 1);
        sub(hr, hl);
    }
    return hr;
}

bool eq(int l1, int l2, int len) {
    return mul(getHash(l1, l1 + len - 1), pw[l2]) == mul(getHash(l2, l2 + len - 1), pw[l1]);
}

int ask(int len0, int len1) {
    int l = 0;
    int l0 = -1, l1 = -1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (l0 == -1)
                l0 = l;
            else {
                if (!eq(l0, l, len0))
                    return 0;
            }
            l += len0;
        } else {
            if (l1 == -1)
                l1 = l;
            else {
                if (!eq(l1, l, len1))
                    return 0;
            }
            l += len1;
        }
    }
    assert(l == n);
    if (len0 == len1 && eq(l0, l1, len0)) // equal
        return 0;
    return 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    
    cin >> s >> t;

    pw[0] = mp(1, 1);
    for (int i = 0; i < t.size(); i++) {
        pw[i + 1] = mul(pw[i], mp(p[0], p[1]));
        h[i] = mul(pw[i], mp(t[i] - 'a' + 1, t[i] - 'a' + 1));
        if (i)
            add(h[i], h[i - 1]);
    }

    int c0 = 0, c1 = 0;

    if (s[0] == '1') {
        for (int i = 0; i < s.size(); i++) {
            s[i] = ((s[i] - '0') ^ 1) + '0';
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            c0++;
        else
            c1++;
    }

    n = t.size();
    int ans = 0;
    for (int len0 = 1; len0 * c0 <= n; len0++) {
        int kek = n - c0 * len0;
        if (kek % c1) continue;
        int len1 = kek / c1;
        if (len1 <= 0) continue;

        ans += ask(len0, len1);
    }

    cout << ans;
    return 0; 
}