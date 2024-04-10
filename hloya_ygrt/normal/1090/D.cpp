#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;


//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 25;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

int a[maxn];
bool can[maxn];

int main() {
    // freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    set<pair<int, int> > q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        q.insert(mp(u, v));
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (!q.count(mp(i, j))) {
                cout << "YES\n";
                int x = 1, y = 3;
                for (int k = 0; k < n; k++)
                    if (k == i || k == j) {
                        cout << x << ' ';
                        x++;
                    } else {
                        cout << y << ' ';
                        y++;
                    }
                cout << endl;
                x = 1, y = 3;
                for (int k = 0; k < n; k++)
                    if (k == i || k == j) {
                        cout << x << ' ';
                        // x++;
                    } else {
                        cout << y << ' ';
                        y++;
                    }
                
                return 0;
            }
    cout << "NO";
    return 0;
}