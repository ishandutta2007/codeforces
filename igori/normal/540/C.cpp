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
double dist_point_line(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double distance = abs((y3 - y1) * x2 - (x3 - x1) * y2 + x3 * y1 - x1 * y3) / (2 * sqrt(sqr(x3 - x1) + sqr(y3 - y1)));
    return distance;
}
double dist_point_point(int x1, int y1, int x2, int y2)
{
    double distance = sqrt(sqr(x1 - y1) + sqr(x2 - y2));
    return distance;
}
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
ll a, b, x, y, z;
ll arr[500100];
ll bs[500100];
string s[560];
int dist[503][503];

int able(int x, int y)
{
    if (x >= n || x < 0 || y >= m || y < 0)
        return 0;
    return 1;
}

int dfs(int x0, int y0)
{
    vector<pii> s1;
    dist[x0][y0] = 1;
    s1.pb({x0, y0});
    for (int i = 0; i < s1.sz; i++)
    {
        int x1 = s1[i].fi;
        int y1 = s1[i].se;
        for (int j = 0; j < 4; j++)
        {
            int x2 = x1 + cx[j];
            int y2 = y1 + cy[j];
            if (able(x2, y2) && dist[x2][y2] == 0 && (s[x2][y2] != 'X' || (x2 == x && y2 == y)))
            {
                dist[x2][y2] = dist[x1][y1]+ 1;
                s1.pb({x2, y2});
                //cout << x2 << " " << y2 << endl;
            }
        }
    }
    
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> a >> b >> x >> y;
    a--;
    b--;
    x--;
    y--;
    int t = 0;
    for (int i = 0; i < 4; i++)
    {
        if (able(x + cx[i], y + cy[i]) && (s[x + cx[i]][y + cy[i]] == '.' || (x + cx[i] == a && y + cy[i] == b)))
        {
            t++;
        }
    }
    if (a == x && b == y)
    {
        if (s[a][b] == 'X')
            if (t >= 1)
                cout << "YES";
            else
                cout << "NO";
        if (s[a][b] == '.')
            if (t >= 2)
                cout << "YES";
            else
                cout << "NO";
        return 0;
    }
    if (s[x][y] == 'X' || t >= 2)
    {
        dfs(a, b);
        if (dist[x][y] > 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
        return 0;
    }
    
}