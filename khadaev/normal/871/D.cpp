#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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

const int N = 1e7 + 10;
int p[N];
int copr[N];
ll pref[N];
ll pref_min_pr[N];

void precalc() {
    vector<int> primes;
    forn(i, 0, N) p[i] = i;
    forn(i, 2, N) {
        if (p[i] == i)
            primes.eb(i);
        for (int x : primes) {
            if (x > p[i]) break;
            ll mul = 1ll * x * i;
            if (mul >= N) break;
            p[mul] = x; 
       }
    }
    copr[1] = 1;
    forn(i, 2, N) {
        int prev = i / p[i];
        copr[i] = copr[prev];
        copr[i] *= p[i];
        if (p[i] != p[prev])
            copr[i] -= copr[i] / p[i];
    }
    pref[1] = copr[1] - 1;
    forn(i, 2, N)
        pref[i] = pref[i - 1] + copr[i];
}

void check(int n) {
    fore(i, 1, n) {
        vector<int> dist(n + 1, INF);
        queue<int> q;
        dist[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            fore(v, 1, n)
                if (__gcd(v, u) > 1 && dist[v] == INF) {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                }
        }
        fore(j, 1, n)
            cout << (dist[j] == INF ? 0 : dist[j]) << ' ';
        cout << '\n';
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    precalc();
    //fore(i, 1, 10) cout << p[i] << ' '; 
    int n;
    cin >> n;
    if (n < 4) {
        cout << 0 << '\n';
        return 0;
    }
    //check(n);
    ll good = n - 1;
    fore(i, 2, n) {
        if (2 * i > n && p[i] == i)
            --good;
    }
    //cerr << good << '\n';
    ll ans = good * (good - 1) / 2 * 3;
    fore(i, 2, n) {
        //cerr << i << ' ' << pref[n / i] << '\n';
        ans -= pref[n / i];
    }
    ll cnt2 = 0;
    fore(i, 2, n)
        ++pref_min_pr[p[i]];

    fore(i, 3, n)
        pref_min_pr[i] += pref_min_pr[i - 1];
    fore(i, 2, n) {
        //cerr << i << ' ' << pref_min_pr[n / p[i]] << '\n';
        cnt2 += pref_min_pr[n / p[i]];
    }
    fore(i, 2, n)
        if (1ll * p[i] * p[i] <= n)
            --cnt2;
    assert(cnt2 % 2 == 0);
    ans -= cnt2 / 2;
    //cerr << cnt2 << '\n';
    cout << ans << '\n';
    
}