/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
    //return (a != 0 ? gcd(b % a, a) : b);
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

int n, k;
string s[N];
int used[N][N];

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    string ans = "";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            used[i][j] = BIG;
    if (s[0][0] == 'a' || k == 0)
    {
        used[0][0] = 0;
        ans += s[0][0];
    }
    else
    {
        used[0][0] = 1;
        ans += 'a';
    }
    for (int i = 0; i < 2 * n - 2; i++)
    {
        int sum = i;
        for (int x = 0; x < n; x++)
        {
            int y = (sum - x);
            if (y < 0 || y >= n) continue;
            if (x != n - 1)
                used[x + 1][y] = min(used[x + 1][y], used[x][y]);
            if (y != n - 1)
                used[x][y + 1] = min(used[x][y + 1], used[x][y]);
        }
        sum = i + 1;
        char z = 'z';
        for (int x = 0; x < n; x++)
        {
            int y = (sum - x);
            if (y < 0 || y >= n) continue;
            if (used[x][y] == BIG) continue;
            if (s[x][y] == 'a' || used[x][y] + 1 > k)
                z = min(s[x][y], z);
            else if (used[x][y] + 1 <= k)
                z = min('a', z);
        }
        ans += z;
        for (int x = 0; x < n; x++)
        {
            int y = (sum - x);
            if (y < 0 || y >= n) continue;
            if (used[x][y] == BIG) continue;
            if (s[x][y] == z)
                continue;
            if (used[x][y] + 1 <= k)
                used[x][y]++;
            else
                used[x][y] = BIG;
        }
    }
    cout << ans;
    return 0;
}