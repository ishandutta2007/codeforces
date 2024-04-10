#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 29;
map<int, int> save;

int brute(int msk) {
    auto it = save.find(msk);
    if (it != save.end()) return it->sn;
    int results = 0;
    fore(i, 1, N) {
        int stay = msk & ((1 << (i - 1)) - 1);
        int nw = stay | ((msk ^ stay) >>  i);
        if (nw != msk) results |= (1 << brute(nw));
    }
    fore(i, 0, N) if ((results & (1 << i)) == 0) {
        save[msk] = i;
        return i;
    }
    assert(false);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int m;
    cin >> m;
    map<int, vector<int>> pws;
    forn(i, 0, m) {
        int n;
        cin >> n;
        for (int j = 2; j * j <= n; ++j) {
            if (n % j) continue;
            int cnt = 0;
            while (n % j == 0) {
                n /= j;
                ++cnt;
            }
            pws[j].eb(cnt);
        }
        if (n > 1) {
            pws[n].eb(1);
        }
    }
    save[0] = 0;
    int ans = 0;
    /*
    for (auto p : pws) {
        auto v = p.sn;
        sort(all(v));
        int prv = 0;
        for (int x : v) {
            ans ^= (x - prv);
            prv = x;
        }
    }*/
    for (auto p : pws) {
        int msk = 0;
        for (int x : p.sn) msk |= (1 << x);
        msk /= 2;
        ans ^= brute(msk);
    }
    cout << (ans == 0 ? "Arpa" : "Mojtaba") << '\n';
}