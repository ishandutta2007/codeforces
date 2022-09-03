#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e3 + 239;

int n, a[M], b[M], c[M], d[M];

bool check(vector<int> id)
{
    if ((int)id.size() == 1) return true;
    vector<tuple<int, int, int> > ev;
    for (int i : id)
    {
        ev.push_back(make_tuple(a[i], 1, i));
        ev.push_back(make_tuple(c[i], -1, i));
    }
    sort(ev.begin(), ev.end());
    int bl = 0;
    for (int i = 0; i < (int)ev.size(); i++)
    {
        bl += get<1>(ev[i]);
        if ((int)ev.size() - 1 == i) break;
        if (bl == 0)
        {
            vector<int> l;
            for (int x = 0; x < i; x++)
                if (get<1>(ev[x]) == 1)
                    l.push_back(get<2>(ev[x]));
            vector<int> r;
            for (int x = i; x < (int)ev.size(); x++)
                if (get<1>(ev[x]) == 1)
                    r.push_back(get<2>(ev[x]));
            return (check(l) && check(r));
        }
    }
    ev.clear();
    for (int i : id)
    {
        ev.push_back(make_tuple(b[i], 1, i));
        ev.push_back(make_tuple(d[i], -1, i));
    }
    sort(ev.begin(), ev.end());
    bl = 0;
    for (int i = 0; i < (int)ev.size(); i++)
    {
        bl += get<1>(ev[i]);
        if ((int)ev.size() - 1 == i) break;
        if (bl == 0)
        {
            vector<int> l;
            for (int x = 0; x < i; x++)
                if (get<1>(ev[x]) == 1)
                    l.push_back(get<2>(ev[x]));
            vector<int> r;
            for (int x = i; x < (int)ev.size(); x++)
                if (get<1>(ev[x]) == 1)
                    r.push_back(get<2>(ev[x]));
            return (check(l) && check(r));
        }
    }
    return false;
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> al;
    for (int i = 0; i < n; i++)
        al.push_back(i);
    cout << (check(al) ? "YES" : "NO");
    return 0;
}