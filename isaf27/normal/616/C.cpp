#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 1e3 + 10;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 18;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int bt = 31;

// Code starts here

struct dsu
{
    vector<int> parent, r, kol;

    dsu()
    {
        parent = r = {};
    }

    dsu(int n)
    {
        parent.resize(n);
        r.resize(n);
        kol.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i, r[i] = 0, kol[i] = 1;
    }

    int find_set(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_set(parent[a]);
    }

    void merge_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a == b)
            return;
        if (r[a] >= r[b])
            swap(a, b);
        parent[a] = b;
        kol[b] += kol[a];
        if (r[a] == r[b])
            r[b]++;
    }

    bool is_connect(int a, int b)
    {
        return find_set(a) == find_set(b);
    }
};

int n, m;
string s[MAX_N];

bool check(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    dsu w = dsu(n * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 4; d++)
            {
                int gx = i + dx[d];
                int gy = j + dy[d];
                if (!check(gx, gy))
                    continue;
                if (s[i][j] == '*' || s[gx][gy] == '*')
                    continue;
                w.merge_set(m * i + j, m * gx + gy);
            }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                cout << ".";
                continue;
            }
            int ans = 1;
            vector<pair<int, int> > t;
            for (int d = 0; d < 4; d++)
            {
                int gx = i + dx[d];
                int gy = j + dy[d];
                if (!check(gx, gy))
                    continue;
                if (s[gx][gy] == '*')
                    continue;
                int dd = w.find_set(gx * m + gy);
                t.push_back(make_pair(dd, w.kol[dd]));
            }
            sort(t.begin(), t.end());
            t.resize(unique(t.begin(), t.end()) - t.begin());
            for (pair<int, int> u : t)
                ans += u.second;
            cout << (ans % 10);
        }
        cout << "\n";
    }
    return 0;
}