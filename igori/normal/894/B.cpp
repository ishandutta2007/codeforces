#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define f(i, n) for (int i = 0; i < n; i++)
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define th third
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
struct trio{
    int first;
    int second;
    int third;
};
struct long_trio{
    ll first;
    ll second;
    ll third;
};
const ll INF = 1e18 + 2;
const int LIT = 505;
const int BIG = 200001;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
ll st_10[10] = {1, 10, 100, 1000, 10000, 1000000, 10000000, 100000000, 1000000000};

//___________BAZE_________________
ll n, m, k, l, r, x, y, t, ans = 1, w, s;
//___________VARIABLES____________

int main()
{
    cin >> n >> m >> k;
    if (k == -1)
    {
        if ((n + m) % 2 == 1)
        {
            cout << 0;
            return 0;
        }
    }
    n--;
    m--;
    n = n % (MOD - 1);
    m = m % (MOD - 1);
    n = (n * m) % (MOD - 1);
    ll i2_in_10_6 = 1;
    for (int i = 0; i < 1000000; i++)
    {
        i2_in_10_6 = (i2_in_10_6 * 2) % MOD;
    }
    while (n > 0)
    {
        if (n > 1000000)
        {
            ans = (ans * i2_in_10_6) % MOD;
            n -= 1000000;
        }
        else
        {
            ans = (ans * 2) % MOD;
            n--;
        }
    }
    cout << ans;
}