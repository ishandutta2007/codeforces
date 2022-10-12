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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18 + 1;
const int MAX = 200001;
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
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min(ll a, ll b)
{
    return -1 * max(-a, -b);
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
ll n, m, ans1, ans2, k;
string s1, s2;
int arr[MAX], b[MAX], c[MAX];
vector<int> ans;

void shift(int x)
{
    ans.pb(x);
    int ind = 0;
    for (int i = 0; i < x; i++)
    {
        b[ind] = arr[n - i - 1];
        ind++;
    }
    for (int i = 0; i < n - x; i++)
    {
        b[ind] = arr[i];
        ind++;
    }
    forn(i, n)
    {
        arr[i] = b[i];
        //cout << arr[i] << " ";
    }
    //cout << endl;
}

int main()
{
    cin >> n >> s1 >> s2;
    int search = 0;
    int q = n / 2 - 1;
    int high = n / 2 + 1;
    int low = n / 2;
    c[0] = n / 2;
    c[1] = n / 2 + 1;
    for (int i = 2; i < n; i++)
    {
        c[i] = q;
        if (q < low)
        {
            low--;
            q = high + 1;
        }
        else
        {
            high++;
            q = low - 1;
        }
    }
    set<int> letters[404];
    k = 1;
    for (int i = 0; i < n; i++)
    {
        letters[s2[i] - 'a'].incert(k);
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        if (letters[s1[i] - 'a'].size() != 0)
        {
            arr[i] = *(letters[s1[i] - 'a'].begin());
            letters[s1[i] - 'a'].erase(letters[s1[i] - 'a'].begin());
        }
        else
        {
            cout << "-1";
            return 0;
        }
    }
    forn(i, n)
    {
        if (arr[i] == c[search])
        {
            //cout << c[search] << endl;
            //cout << n - i << endl;
            shift(n - i - 1);
            shift(n);
            search++;
            break;
        }
    }
    for (search = 1; search < n; search++)
    {
        forn(i, n)
        {
            if (arr[i] == c[search])
            {
                shift(n - i - 1);
                shift(n - (n - i - 1) - search);
                shift(search);
                //cout << endl;
                break;
            }
        }
    }
    if (arr[0] == n)
        shift(n);
    cout << ans.sz << endl;
    forn(i, ans.sz)
    {
        cout << ans[i] << " ";
    }
}