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

int a[maxn], ans[maxn];


int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<pii> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // n - a[i]   
        r.pb(mp(a[i], i));
    }

    sort(all(r));

    int cur = 1;
    for (int i = 0; i < n; i++) {
        int j = i;
        int cnt = n - r[i].f - 1;
        while (j + 1 < r.size() && r[j + 1].f == r[j].f && cnt > 0) {
            ans[r[j + 1].s] = cur;
            cnt--;
            j++;
        }

        if (cnt != 0) {
            cout << "Impossible";
            return 0;
        }

        ans[r[i].s] = cur;

        cur += 1;
        i = j;
    }

    cout << "Possible\n";
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}