//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 1e4 + 239;

int a[6];
int b[M];
int n;

vector<int> pos[M];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
            events.emplace_back(b[i] - a[j], i);
    sort(events.begin(), events.end());
    for (int i = 0; i < 6 * n; i++)
        pos[events[i].second].push_back(i);
    for (int i = 0; i < n; i++)
        reverse(pos[i].begin(), pos[i].end());
    set<int> last;
    for (int i = 0; i < n; i++)
        last.insert(pos[i].back());
    int ans = BIG;
    for (int i = 0; i < 6 * n; i++)
    {
        ans = min(ans, events[*last.rbegin()].first - events[i].first);
        int t = events[i].second;
        last.erase(pos[t].back());
        pos[t].pop_back();
        if (pos[t].empty())
            break;
        last.insert(pos[t].back());
    }
    cout << ans << "\n";
    return 0;
}