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
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
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
//___________BAZE_________________
ll n, m, k, l, r, x, y, xk, yk, how, can, ks, ans1, ans2, ans3, a, b, c;
ll factorial[5040];
ll select[5040][5040];
const ll MOD = 998244353;
//___________VARIABLES____________

int main()
{
    cin >> a >> b >> c;
    factorial[0] = 1;
    for (int i = 1; i <= 5000; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    for (int i = 0; i <=5000; i++)
    {
        for (int j = 0; j <= 5000; j++)
        {
            if (i == 0 || i == j)
                select[j][i] = 1;
        }
    }
    for (int i = 1; i <= 5000; i++)
    {
        for (int j = 1; j <= 5000; j++)
        {
            if (j > i)
                break;
            select[i][j] = (select[i - 1][j] + select[i - 1][j - 1]) % MOD;
        }
    }
    for (int i = 0; i <= min(a, b); i++)
    {
        ans1 = (ans1 + (select[a][i] * select[b][i]) % MOD * factorial[i]) % MOD;
    }
    for (int i = 0; i <= min(a, c); i++)
    {
        ans2 = (ans2 + (select[a][i] * select[c][i]) % MOD * factorial[i]) % MOD;
    }
    for (int i = 0; i <= min(b, c); i++)
    {
        ans3 = (ans3 + (select[b][i] * select[c][i]) % MOD * factorial[i]) % MOD;
    }
    cout << ((ans1 * ans2) % MOD) * ans3 % MOD;
}