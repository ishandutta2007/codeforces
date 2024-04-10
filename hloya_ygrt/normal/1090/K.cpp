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

string s[maxn], t[maxn];

int main() {
    int n;
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    cin >> n;

    vector<pair<pair<string, int>, int> > f;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];

        int msk = 0;
        for (int j = 0; j < t[i].size(); j++)
            msk |= 1 << (t[i][j] - 'a');

        while (s[i].size() && (msk & (1 << (s[i].back() - 'a'))))
            s[i].pop_back();

        f.pb(mp(mp(s[i], msk), i));
    }

    vector<vector<int> > ans;

    sort(all(f));

    vector<int> cur;
    for (int i = 0; i < n; i++) {
        int j = i;
        cur.clear();
        cur.pb(f[i].s);
        while (j + 1 < n && f[j + 1].f == f[i].f) {
            j++;
            cur.pb(f[j].s);
        }
        ans.pb(cur);
        i = j;
    }

    cout << ans.size() << "\n";
    for (int i = 0;  i < ans.size(); i++) {
        cout << ans[i].size() << ' ';
        for (int j : ans[i])
            cout << j + 1 << ' ';
        cout << "\n";
    }
    return 0;
}