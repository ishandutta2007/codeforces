#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
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
ll n, m, ans1, ans2;
ll arr[500100];
ll bs[500100];
string s1, s2, s3;

int main()
{
    cin >> s1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s2;
        if (s2.sz != s1.sz)
        {
            continue;
        }
        int e = 0;
        for (int j = 0; j < s1.sz; j++)
        {
            if (s1[j] == s2[j])
                continue;
            if (s1[j] == '0' || s1[j] == 'O' || s1[j] == 'o')
                if (s2[j] == '0' || s2[j] == 'O' || s2[j] == 'o')
                    continue;
            if (s1[j] == '1' || s1[j] == 'I' || s1[j] == 'l' || s1[j] == 'i' || s1[j] == 'L')
                if (s2[j] == '1' || s2[j] == 'I' || s2[j] == 'l' || s2[j] == 'i' || s2[j] == 'L')
                    continue;
            if (abs(s1[j] - s2[j]) == abs('A' - 'a'))
                continue;
            e = 1;
        }
        if (e == 0)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}