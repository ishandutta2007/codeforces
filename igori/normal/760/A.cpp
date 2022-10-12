#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;
#define sqr(z) (z) * (z)
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
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i++)
#define nfor(i, n) for (int (i) = (n) - 1; (i) != -1; i--)
#define do_nothing cout << " Work_Error ";
#define erace erase
#define incert insert
#define pre pre1234
#define re return
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
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
double inq(double k, int q)
{
    if (q == 0)
        return 1;
    double l = inq(k, q / 2);
    if (q % 2 == 0)
        return l * l;
    else
        return l * l * k;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll cubr(ll a)
{
    ll l = -1, r = 1e6 + 2;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return l;
}
ll possible(ll q)
{
    if (q == INF)
        return -1;
    return q;
}
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
//___________BAZE_________________
ll n, m, op, l, r;
string s;

int main()
{
    cin >> n >> m;
    ll k = days[n - 1];
    k += m - 1;
    if (k <= 28)
    cout << 4;
    else
    if (k <= 35)
    cout << 5;
    else
    cout << 6;
    
}