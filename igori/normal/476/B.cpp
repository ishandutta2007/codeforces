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
ll n, m, k;
string s1, s2;
vector<int> a;

//___________VARIABLES____________

double ans, ans2;

void check()
{
    int t = 1;
    int x = 0;
    for (int i = 0; i < s2.sz; i++)
    {
        if (s2[i] == '+' && a[i] == 0)
            t = 0;
        if (s2[i] == '-' && a[i] == 1)
            t = 0;
        if (a[i] == 1)
            x++;
        else
            x--;
    }
    if (x == m && t == 1)
        ans++;
    if (t == 1)
        ans2++;
}

void rec(int x)
{
    if (x == s2.sz)
    {
        check();
        return;
    }
    x++;
    for (int i = 0; i < 2; i++)
    {
        a.pb(i);
        rec(x);
        a.pop_back();
    }
    x--;
    return;
}

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < s1.sz; i++)
    {
        if (s1[i] == '+')
            m++;
        else
            m--;
    }
    rec(0);
    if (ans2 == 0)
        {
            cout << 0;
            return 0;
        }
    printf("%.9f", ans / ans2);
}