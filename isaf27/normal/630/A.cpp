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
#include <deque>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define forn(i, l, r) for (int i = l; i < r; i++)
const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int prost = 239;
const ll prost64 = 239;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int MAX_N = 200001;
const int km = (1 << 18) - 1;

string int_to_str(ll n)
{
    if (n == 0)
        return "";
    return int_to_str(n / 10) + (char)('0' + n % 10);
}

ll str_to_int(string s)
{
    ll ans = 0;
    for (char x : s)
        ans = 10LL * ans + (x - '0');
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    #endif // ONLINE_JUDGE
    fast_read;
    cout << 25;
    return 0;
}