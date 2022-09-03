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
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

int n, p[M];
vector<pair<int, int> > ans;

void make_swap(int i, int j)
{
    if (i == j) return;
    swap(p[i], p[j]);
    ans.push_back(make_pair(i, j));
}

void swap_two(int i, int j)
{
    if (2 * abs(i - j) >= n)
    {
        make_swap(i, j);
        return;
    }
    if (2 * i >= n && 2 * j >= n)
    {
        make_swap(0, i);
        make_swap(0, j);
        make_swap(0, i);
        return;
    }
    if (2 * (n - 1 - i) >= n && 2 * (n - 1 - j) >= n)
    {
        make_swap(n - 1, i);
        make_swap(n - 1, j);
        make_swap(n - 1, i);
        return;
    }
    if (i > j) swap(i, j);
    make_swap(n - 1, i);
    make_swap(0, n - 1);
    make_swap(0, j);
    make_swap(0, n - 1);
    make_swap(n - 1, i);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++)
        while (p[i] != i)
            swap_two(p[i], i);
    cout << (int)ans.size() << "\n";
    for (pair<int, int> t : ans)
        cout << t.first + 1 << " " << t.second + 1 << "\n";
    //for (int i = 0; i < n; i++)
    //    cerr << p[i] + 1 << " ";
    //cerr << "\n";
    return 0;
}