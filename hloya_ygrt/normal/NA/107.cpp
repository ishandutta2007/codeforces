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
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5+500;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const int base2 = (int) 1e9 + 9;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const int pp = 41;
const int pp2 = 37;
const int INF = (int) 2e9;

bool kek(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    cout.flush();
    string res;
    cin >> res;
    if (res == "x")
        return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen ("input.txt", "r", stdin);
    
    string s;
    while (cin >> s) {
        if (s == "end")
            exit(0);
        if (kek(0, 1) == 1) {
            cout << "! 1" << endl;
            cout.flush();
            continue;
        }
        int x = 1;
        while (1) {
            bool res = kek(x, 2 * x);
            if (res == 1) {
                ll l = x + 1, r = 2 * x;
                while (r - l > 0) {
                    ll m = (l + r) / 2;
                    if (kek(x, m) == 1)
                        r = m;
                    else
                        l = m + 1;
                }
                cout << "! " << l << endl;
                cout.flush();
                break;
            }
            x *= 2;
        }
    }
    return 0;
}