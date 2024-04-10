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

int p[M];
int n;
vector<pair<int, int>> events;

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        char x;
        int p;
        cin >> x;
        if (x == '+')
            events.emplace_back(0, 0);
        else
        {
            cin >> p;
            events.emplace_back(1, p);
        }
    }
    vector<int> pos;
    int c = 0;
    for (auto [type, pc] : events)
    {
        if (type == 0)
        {
            pos.push_back(c++);
            continue;
        }
        if (pos.empty())
        {
            cout << "NO\n";
            return 0;
        }
        p[pos.back()] = pc;
        pos.pop_back();
    }
    set<int> cur;
    c = 0;
    for (auto [type, pc] : events)
    {
        if (type == 0)
        {
            cur.insert(p[c++]);
            continue;
        }
        if (cur.empty())
        {
            cout << "NO\n";
            return 0;
        }
        if (*cur.begin() != pc)
        {
            cout << "NO\n";
            return 0;
        }
        cur.erase(cur.begin());
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n";
    return 0;
}