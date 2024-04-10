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
#include <stdio.h>
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
ll dsumm(ll x, ll k)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; y < 1e18; i++)
    {
        z += x / y % k;
        y *= k;
    }
    return z;
}
ll dcount(ll x)
{
    ll y = 1;
    ll z = 0;
    int c[100];
    for (int i = 0; i < 10; i++)
    c[i] = 0;
    for (int i = 0; x > 0; i++)
    {
        if (c[x / y % 10] == 0)
        z++;
        c[x / y % 10] = 1;
        x /= 10;
    }
    return z;
}

#define bitcount __builtin_popcount
#define bitcountl __builtin_popcountll

string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//______________________
ll n, m;
string s;
string t[1404040];
ll meanings_of_lists[1404040];
ll is_list[1404040];
ll root[1404040];
ll classic[1404040];
ll ls[1404040];
ll rs[1404040];
ll result_if_changed[1404040];
ll dist[1404040];
ll visited[1404040];
vector<int> sorted_by_dist;

int build(int x)
{
    if (t[x] == "NOT")
    {
        classic[x] = 1 - build(ls[x]);
    }
    if (t[x] == "OR")
    {
        classic[x] = max(build(ls[x]), build(rs[x]));
    }
    if (t[x] == "XOR")
    {
        classic[x] = build(ls[x]) ^ build(rs[x]);
    }
    if (t[x] == "AND")
    {
        classic[x] = min(build(ls[x]), build(rs[x]));
    }
    return classic[x];
}

void bfs(int x)
{
    sorted_by_dist.push_back(x);
    dist[x] = 1;
    for (int i = 0; i < sorted_by_dist.size(); i++)
    {
        int v = sorted_by_dist[i];
        if (ls[v] != 0)
        {
            if (dist[ls[v]] == 0)
            {
                dist[ls[v]] = dist[v] + 1;
                sorted_by_dist.pb(ls[v]);
            }
        }
        if (rs[v] != 0)
        {
            if (dist[rs[v]] == 0)
            {
                dist[rs[v]] = dist[v] + 1;
                sorted_by_dist.pb(rs[v]);
            }
        }
    }
}

int main()
{
    cin >> n;
    dist[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        if (t[i] == "IN")
        {
            cin >> meanings_of_lists[i];
            classic[i] = meanings_of_lists[i];
            is_list[i] = 1;
        }
        else
        if (t[i] == "NOT")
        {
            cin >> ls[i];
            root[ls[i]] = i;
        }
        else
        {
            cin >> ls[i] >> rs[i];
            root[ls[i]] = i;
            root[rs[i]] = i;
        }
    }
    build(1);
    bfs(1);
    result_if_changed[1] = 1 - classic[1];
    for (int i = 1; i < n; i++)
    {
        int vertex = sorted_by_dist[i];
        int root_ = root[vertex];
        int new_ = 1 - classic[vertex];
        if (t[root_] == "NOT")
        {
            result_if_changed[vertex] = result_if_changed[root_];
        }
        if (t[root_] == "OR")
        {
            int rs_root = rs[root_];
            int ls_root = ls[root_];
            if (vertex == ls[root_])
            {
                int z1 = new_;
                int z2 = classic[rs_root];
                if (max(z1, z2) == classic[root_])
                {
                    result_if_changed[vertex] = classic[1];
                }
                else
                {
                    result_if_changed[vertex] = result_if_changed[root_];
                }
            }
            if (vertex == rs[root_])
            {
                int z2 = new_;
                int z1 = classic[ls_root];
                if (max(z1, z2) == classic[root_])
                {
                    result_if_changed[vertex] = classic[1];
                }
                else
                {
                    result_if_changed[vertex] = result_if_changed[root_];
                }
            }
        }
        if (t[root_] == "XOR")
        {
            int rs_root = rs[root_];
            int ls_root = ls[root_];
            if (vertex == ls[root_])
            {
                int z1 = new_;
                int z2 = classic[rs_root];
                if ((z1 ^ z2) == classic[root_])
                {
                    result_if_changed[vertex] = classic[1];
                }
                else
                {
                    result_if_changed[vertex] = result_if_changed[root_];
                }
            }
            if (vertex == rs[root_])
            {
                int z2 = new_;
                int z1 = classic[ls_root];
                if ((z1 ^ z2) == classic[root_])
                {
                    result_if_changed[vertex] = classic[1];
                }
                else
                {
                    result_if_changed[vertex] = result_if_changed[root_];
                }
            }
        }
        if (t[root_] == "AND")
        {
            int rs_root = rs[root_];
            int ls_root = ls[root_];
            if (vertex == ls[root_])
            {
                int z1 = new_;
                int z2 = classic[rs_root];
                if (min(z1, z2) == classic[root_])
                {
                    result_if_changed[vertex] = classic[1];
                }
                else
                {
                    result_if_changed[vertex] = result_if_changed[root_];
                }
            }
            if (vertex == rs[root_])
            {
                int z2 = new_;
                int z1 = classic[ls_root];
                if (min(z1, z2) == classic[root_])
                {
                    result_if_changed[vertex] = classic[1];
                }
                else
                {
                    result_if_changed[vertex] = result_if_changed[root_];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (is_list[i] == 1)
        {
            cout << result_if_changed[i];
        }
    }
}