//#pragma GCC optimize("O3")
#ifdef ONPC
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

int n, m, a[M], b[M];
bool used[M];
vector<pair<int, int> > v[M];
set<int> q;

void kill(int p)
{
    used[p] = true;
    for (pair<int, int> t : v[p])
        if (q.find(t.second) != q.end())
            q.erase(t.second);
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < 3 * n; i++)
    {
        used[i] = false;
        v[i].clear();
    }
    q.clear();
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(make_pair(f, i));
        v[f].push_back(make_pair(s, i));
        a[i] = s, b[i] = f;
        q.insert(i);
    }
    vector<int> ret;
    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        {
            vector<int> ans;
            for (int x = 0; x < 3 * n && ans.size() < n; x++)
                if (!used[x])
                    ans.push_back(x);
            cout << "IndSet\n";
            for (int x : ans)
                cout << x + 1 << " ";
            cout << "\n";
            return;
        }
        int p = *q.begin();
        ret.push_back(p);
        kill(a[p]);
        kill(b[p]);
    }
    cout << "Matching\n";
    for (int i : ret)
        cout << i + 1 << " ";
    cout << "\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}