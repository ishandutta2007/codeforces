//#pragma GCC optimize("O3")
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
const int X = 2e3 + 239;

int n, qt;
ll x, mx;
deque<ll> q;
vector<pair<int, int> > al;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> qt;
    mx = 0;
    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        q.push_back(b);
        mx = max(mx, b);
    }
    while (q[0] != mx)
    {
        al.push_back(make_pair(q[0], q[1]));
        q.pop_front();
        q.pop_front();
        q.push_front(max(al.back().first, al.back().second));
        q.push_back(min(al.back().first, al.back().second));
    }
    for (int i = 0; i < qt; i++)
    {
        cin >> x;
        x--;
        if (x < (int)al.size())
            cout << al[x].first << " " << al[x].second << "\n";
        else
        {
            x -= (ll)al.size();
            cout << q[0] << " " << q[(1LL + (ll)(x % (ll)(n - 1)))] << "\n";
        }
    }
    return 0;
}