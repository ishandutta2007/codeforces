// Code it, hate me?
// .................
// WA 138 or TL 109?
// Hope, Accepted...

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
#define reverce reverse
#define re return
#define pre pre1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
const ll INF = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
ll inq(ll k, ll q)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2);
    if (q % 2 == 0)
        return l * l % MOD;
    else
        return l * l * k % MOD;
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
bool correct(int x, int xx)
{
    if (x < 0)
        return 0;
    if (x >= xx)
        return 0;
    return 1;
}
ll dsumm(ll x)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; i < 18; i++)
    {
        z += x / y % 10;
        y *= 10;
    }
    return z;
}
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//______________________
ll n, m, k, x, y, ans2;
struct marray{
    ll x[500000];
    ll n;
    void read(int i)
    {
        cin >> x[i];
    }
    void readall()
    {
        forn(i, n)
        {
            cin >> x[i];
        }
    }
    void gen()
    {
        forn(i, n)
        {
            x[i] = (i * 12345) % 58494939;
        }
    }
    void write(int i)
    {
        cout << x[i] << " ";
    }
    void writeall()
    {
        forn(i, n)
        {
            cout << x[i] << " ";
        }
    }
    void msort()
    {
        sort(x, x + n);
    }
    void mrev()
    {
        reverce(x, x + n);
    }
    map<ll, int> mcount()
    {
        map<ll, int> r;
        forn(i, n)
        {
            r[x[i]]++;
        }
        return r;
    }
    int upperbound(ll y)
    {
        int l = -1, r = n;
        while (r > l + 1)
        {
            int mid = (l + r) / 2;
            if (x[mid] > y)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
    int lowerbound(ll y)
    {
        int l = -1, r = n;
        while (r > l + 1)
        {
            int mid = (l + r) / 2;
            if (x[mid] >= y)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
    void make()
    {
        
    }
};
struct mgraph{
    vector<int> graph[201000];
    int dist[200100];
    void edge(int x, int y)
    {
        graph[x].pb(y);
        graph[y].pb(x);
    }
    void bfs(int x)
    {
        vector<int> s;
        mm(dist);
        s.pb(x);
        dist[x] = 0;
        for (int i = 0; i < s.sz; i++)
        {
            int y = s[i];
            for (int j = 0; j < graph[y].sz; j++)
            {
                int z = graph[y][j];
                if (dist[z] == -1)
                {
                    dist[z] = dist[y] + 1;
                    s.pb(z);
                }
            }
        }
    }
}g;

map <int, int> mm, mm2;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mm[x] = i + 1;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        char a;
        cin >> a;
        if (a == '0')
        {
            cout << mm.begin() -> se << " ";
            mm2[mm.begin() -> fi] = mm.begin() -> se;
            mm.erace(mm.begin());
        }
        else
        {
            auto it = mm2.end();
            it--;
            cout << it->se << " ";
            mm2.erace(it);
        }
    }
}