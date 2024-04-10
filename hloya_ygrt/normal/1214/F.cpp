#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include <list>

// hloya template v25
  
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
  
#include <bits/stdc++.h>
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
  
template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}
 
// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e6 + 12;//, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
const double PI = acos(-1.0);
 
const int mod= 1e9 + 7;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}

bool distmode;

int dist(int m, int a, int b) {
    if (a == b) {
        return 0;
    }
    if (distmode == 0) {
        if (a < b)
            return b - a;
        else
            return a + m - b;
    } else {
        if (a > b)
            return a - b;
        else
            return a + m - b;
    }
}

int distb(int m, int a, int b) {
    if (a > b) swap(a, b);
    return min(b - a, a + m - b);
}

int brute(int m, vector<int> a, vector<int> b) {
    sort(all(b));
    int res = inf;
    do {
        int cur = 0;
        for (int i = 0; i < a.size(); i++) {
            cur += distb(m, a[i], b[i]);
        }
        amin(res, cur);
    } while (next_permutation(all(b)));
    return res;
}

void gen(int& m, vector<int>& a, vector<int>& b) {
    m = rand() % 10 + 5;
    int n = 6;
    a.clear();
    b.clear();
    for (int i = 0; i < n; i++) {
        a.pb(rand() % m);
        b.pb(rand() % m);
    }
}

int solve(int m, vector<int> a, vector<int> b) {
    vector<int> usa(a.size(), 0), usb(a.size(), 0);
    assert(a.size() == b.size());
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        int mn = inf, i1, i2;
        for (int j = 0; j < a.size(); j++)
            if (!usa[j])
                for (int k = 0; k < a.size(); k++)
                    if (!usb[k]) {
                        if (dist(m, a[j], b[k]) < mn) {
                            mn = dist(m, a[j], b[k]);
                            i1 = j;
                            i2 = k;
                        }
                    }
        res += mn;
        // if (mn == inf) {
        //     cout << i << endl;
        // }
        usa[i1] = 1;
        usb[i2] = 1;
    }
    return res;
}


int solve2(int m, vector<int> a, vector<int> b) {
    vector<pii> ev;
    for (auto e : a) {
        ev.pb(mp(e, 0));
    }
    for (auto e : b) {
        ev.pb(mp(e, 1));
    }
    sort(all(ev));

    int res = inf;
    vector<pii> st;

    int mxdist = -inf;
    for (int i = 0; i < ev.size(); i++) {
        amax(mxdist, dist(m, ev[i].f, ev[(i + 1) % ev.size()].f));
    }
    distmode = 0;
    for (int i = 0; i < ev.size(); i++) {
        if (true) {        
            int cur = 0;

            int ind = i;
            for (int j = 0; j < ev.size(); j++) {
                if (st.empty() || st.back().s == ev[ind].s) {
                    st.pb(ev[ind]);
                } else {
                    cur += dist(m, st.back().f, ev[ind].f);
                    st.pop_back();
                }
                ind += 1;
                if (ind == ev.size())
                    ind = 0;
            }
            amin(res, cur);
            // break;
        }
    }
    distmode = 1;
    reverse(all(ev));
    for (int i = 0; i < ev.size(); i++) {
        if (true) {
            vector<pii> st;
            int cur = 0;

            for (int j = 0; j < ev.size(); j++) {
                int ind = (j + i) % ev.size();
                if (st.empty() || st.back().s == ev[ind].s) {
                    st.pb(ev[ind]);
                } else {
                    cur += dist(m, st.back().f, ev[ind].f);
                    st.pop_back();
                }
            }
            amin(res, cur);
        }
    }
    return res;
}

struct mda {
    int f, s, id;
    bool operator <(const mda& t) const {
        return mp(f, s) < mp(t.f, t.s);
    }
};

ll solve3(int m, vector<int> a, vector<int> b, vector<int>& psans) {
    vector<mda> ev;
    for (int i = 0; i < a.size(); i++) {
        ev.pb({a[i], -1, i});
    }
    for (int i = 0; i < a.size(); i++) {
        ev.pb({b[i], 1, i});
    }
    sort(all(ev));

    map<int, ll> ccu, ccd;
    for (int i = 0, bal = 0; i < ev.size(); i++) {
        if (ev[i].s == -1)
            ccd[bal] += ev[i].f;
        else
            ccu[bal] += ev[i].f;
        bal += ev[i].s;
    }

    ll sa = 0, sb = 0;
    for (auto e : ccu) {
        if (e.f < 0) {
            sb += e.s;
        } else {
            sa += e.s;
        }
    }

    for (auto e : ccd) {
        if (e.f > 0) {
            sb += e.s;
        } else {
            sa += e.s;
        }
    }

    ll ans = sb - sa;
    int addToAll = 0;
    int res = 0;

    for (int i = 0; i + 1 < ev.size(); i++) {
        int rb = 0;
        if (ev[i].s == -1) {
            ccd[rb - addToAll] -= ev[i].f;
            sa -= ev[i].f;
            sb += ev[i].f + m;

            ll dg = ccu[-1 - addToAll];
            sb -= dg;
            sa += dg;

            ll dg2 = ccd[0 - addToAll];
            sa -= dg2;
            sb += dg2;

            ccd[+1 - addToAll] += ev[i].f + m;
        } else {
            ccu[rb - addToAll] -= ev[i].f;
            sa -= ev[i].f;
            sb += ev[i].f + m;

            ll dg = ccd[1 - addToAll];
            sb -= dg;
            sa += dg;

            ll dg2 = ccu[0 - addToAll];
            sa -= dg2;
            sb += dg2;

            ccu[-1 - addToAll] += ev[i].f + m;
        }

        addToAll -= ev[i].s;

        if (sb - sa < ans) {
            ans = sb - sa;
            res = i + 1;
        }
    }

    vector<mda> st;
    vector<int> ps(a.size());

    for (int i = 0; i < ev.size(); i++) {
        int ind = (res + i) % ev.size();
        if (st.empty() || st.back().s == ev[ind].s) {
            st.pb(ev[ind]);
        } else {
            // cur += dist(m, st.back().f, ev[ind].f);
            auto a = st.back();
            auto b = ev[ind];
            if (a.s == 1) swap(a, b);
            ps[a.id] = b.id;
            // cout << "kek";

            st.pop_back();
        }
    }

    psans = ps;

    return ans;
}

vector<int> ans;
ll solve4(int m, vector<int> a, vector<int> b) {
    vector<int> ps, ps2;
    ll kek = solve3(m, a, b, ps);
    for (int i = 0; i < a.size(); i++) {
        a[i] = m - a[i] - 1;
        b[i] = m - b[i] - 1;
    }
    ll mda = solve3(m, a, b, ps2);
    if (mda < kek) {
        ans = ps2;
    } else {
        ans = ps;
    }
    return min(mda, kek);
}

int main() {
    // files1;
    fast_io;

    // srand(time(0));


    int m, n;
    cin >> m >> n;
    // cin >> n >> m;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }
    cout << solve4(m, a, b) << "\n";
    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    // cout << solve4(10, {0, 3, 7}, {7, 2, 5});
    return 0;
    int cnt = 0;
    const int it = 10000;
    for (int iter = 0; iter < it; iter++) {
        int m;
        vector<int> a, b;
        gen(m, a, b);
        // return 0;
        int ans1, ans2;
        if ((ans1 = brute(m, a, b)) != (ans2 = solve4(m, a, b))) {
            cnt++;
            cout << ans1 << ' ' << ans2 << endl;
            cout << m << endl;
            for (auto e : a)
                cout << e << ',';
            cout << endl;
            for (auto e : b)
                cout << e << ',';
            exit(0);
        }
    }
    cout << 1. * cnt / it << endl;
    if (cnt == 0) cout << "ok";
    return 0;
}