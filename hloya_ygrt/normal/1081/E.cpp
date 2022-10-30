#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC optimize("unroll-loops")
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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef list<int> vi;

//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 22;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = (ll) 1e18 + 5;
const int inf = 2e9 + 5;

int main() {
    // freopen("input.txt", "r", stdin);

    ll r = 0;   
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    vector<ll> re;

    for (int i = 0; i < n / 2; i++) {
        ll x;
        cin >> x;

        ll fndf = llinf;
        for (int j = 1; 1ll * j * j <= x; j++) {
            if (x % j == 0) {
                ll q1 = j;
                ll q2 = x / j;

                ll s = q1 + q2;
                if (s % 2) continue;
                
                ll b = s / 2;
                ll a = q2 - b;

                if (a <= 0) continue;

                ll f = a * a - r;
                if (f <= 0) continue;

                if (f + x + r != b * b) {
                    continue;
                }
                
                fndf = min(fndf, f);
            }
        }

        if (fndf == llinf)  {
            cout << "No";
            return 0;
        }

        re.pb(fndf);
        re.pb(x);

        r += fndf;
        r += x;
    }

    cout << "Yes\n";
    for (auto e : re)
        cout << e << ' ';
    return 0;
}