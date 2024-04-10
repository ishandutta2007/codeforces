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
int arr[1003];
int type[102003];
int color[102003];
int flag;
vector<int> colors[302002];
vector<int> free_[103200];
ll easyer[509][509];

void bfs(int x)
{
    color[x] = flag;
    forn(i, free_[x].sz)
    {
        if (color[free_[x][i]] == 0)
        {
            bfs(free_[x][i]);
        }
    }
    return;
}

int main()
{
    cin >> n >> m >> k;
    int qq = 1;
    
    forn(i, k)
    {
        forn(j, k)
        {
            easyer[i][j] = INF;
        }
        cin >> arr[i];
        int bazel = qq;
        while (qq < arr[i] + bazel)
        {
            type[qq] = i;
            qq++;
        }
    }
    
    forn(i, m)
    {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        if (a3 == 0)
        {
            free_[a1].pb(a2);
            free_[a2].pb(a1);
        }
        easyer[type[a1]][type[a2]] = min(easyer[type[a1]][type[a2]], a3);
        easyer[type[a2]][type[a1]] = min(easyer[type[a2]][type[a1]], a3);
    }
    type[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            flag++;
            bfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        colors[type[i]].pb(color[i]);
        if (colors[type[i]].sz >= 2)
        {
            if (colors[type[i]][0] != colors[type[i]][1])
            {
                cout << "No";
                return 0;
            }
            else
                colors[type[i]].resize(1);
        }
    }
    cout << "Yes\n";
    forn(visit, k)
    {
        forn(i, k)
        {
            forn(j, k)
            {
                easyer[i][j] = min(easyer[i][j], easyer[i][visit] + easyer[visit][j]);
            }
        }
    }
    forn(i, k)
    {
        forn(j, k)
        {
            if (i == j)
                cout << 0 << " ";
            else
                cout << possible(easyer[i][j]) << " ";    
        }
        cout << endl;
    }
}