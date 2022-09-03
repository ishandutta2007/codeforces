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
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
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
const ll MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 101;
const int MAX_M = 5001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
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
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

bool dp[two][alf][MAX_N][MAX_N];
int n, m, tto[MAX_N];
bool used[MAX_N];
vector<vector<pair<int, char> > > v(MAX_N);
vector<int> to[alf][MAX_N];
vector<int> topsort;

void dfs(int s)
{
    used[s] = true;
    for (pair<int, char> t : v[s])
        if (!used[t.first])
            dfs(t.first);
    topsort.push_back(s);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m;
    memset(tto, 0, sizeof(tto));
    for (int i = 0; i < m; i++)
    {
        int s, f;
        char x;
        cin >> s >> f >> x;
        s--, f--;
        tto[f]++;
        to[x - 'a'][s].push_back(f);
        v[s].push_back(make_pair(f, x));
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++)
        if (tto[i] == 0)
            dfs(i);
    reverse(topsort.begin(), topsort.end());
    //for (int i : topsort)
    //    cerr << i << " ";
    //cerr << "\n";
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            for (int c = alf - 1; c >= 0; c--)
                for (int d = 0; d < two; d++)
                {
                    int x = topsort[i];
                    int y = topsort[j];
                    if (c != alf - 1)
                        dp[d][c][x][y] = dp[d][c + 1][x][y];
                    if (dp[d][c][x][y])
                        continue;
                    if (d == 0)
                    {
                        if (to[c][x].empty())
                            continue;
                        for (int r : to[c][x])
                            if (!dp[1 - d][c][r][y])
                            {
                                dp[d][c][x][y] = 1;
                                break;
                            }
                    }
                    else
                    {
                        if (to[c][y].empty())
                            continue;
                        for (int r : to[c][y])
                            if (!dp[1 - d][c][x][r])
                            {
                                dp[d][c][x][y] = 1;
                                break;
                            }
                    }
                }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[0][0][i][j])
                cout << "A";
            else
                cout << "B";
        }
        cout << "\n";
    }
    return 0;
}