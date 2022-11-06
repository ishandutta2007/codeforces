#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
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

const string st = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string s1 = "What are you doing while sending \"";
const string s2 = "\"? Are you busy? Will you send \"";
const string s3 = "\"?";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    vector<ll> len(100, LINF);
    len[0] = st.length();
    for (int i = 1; i < 100; ++i) {
        len[i] = 2 * len[i - 1] + s1.length() + s2.length() + s3.length();
        if (len[i] > LINF) {
            len[i] = LINF;
            break;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        --k;
        while (1) {
            ll ln = n >= 100 ? LINF : len[n];
            if (k >= ln) {
                cout << '.';
                break;
            }
            if (n == 0) {
                cout << st[k];
                break;
            }
            ll ln1 = n - 1 >= 100 ? LINF : len[n - 1];
            if (k < s1.length()) {
                cout << s1[k];
                break;
            }
            k -= s1.length();
            if (k < ln1) {
                --n;
                continue;
            }
            k -= ln1;
            if (k < s2.length()) {
                cout << s2[k];
                break;
            }
            k -= s2.length();
            if (k < ln1) {
                --n;
                continue;
            }
            k -= ln1;
            cout << s3[k];
            break;
        }
    }
}