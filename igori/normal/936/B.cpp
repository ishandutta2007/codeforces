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
ll n, m, ans1, ans2, k, s11;
string s1, s2;
int arr[MAX], b[MAX], c[MAX];
set<int> color[100010];
vector<int> graph[100010];
vector<int> pre[100010];
int dist[100010];
int colors[100010];
int cicl;

void dfs(int x)
{
    colors[x] = 1;
    for (int i = 0; i < graph[x].sz; i++)
    {
        if (colors[graph[x][i]] == 0)
        {
            dfs(graph[x][i]);
        }
        else
        if (colors[graph[x][i]] == 1)
        {
            cicl = 1;
        }
    }
    colors[x] = 2;
    return;
}

int bfs(int x)
{
    vector<int> s;
    s.pb(x);
    color[x].incert(1);
    dist[x] = 0;
    forn(i, s.sz)
    {
        int y = s[i];
        for(int j = 0; j < graph[y].sz; j++)
        {
            int z = graph[y][j];
            if (color[z].sz == 0)
            {
                color[z].incert(1 - *color[y].begin());
                if (color[y].sz == 2)
                {
                    color[z].incert(0);
                }
                s.pb(z);
                pre[z].pb(y);
            }
            else
            if (color[z].sz == 1)
            {
                if (color[y].sz == 1 && *color[z].begin() == 1 - *color[y].begin())
                    continue;
                color[z].incert(1 - *color[y].begin());
                if (color[y].sz == 2)
                    color[z].incert(0);
                s.pb(z);
                pre[z].pb(y);
            }
        }
    }
}

int main()
{
    mm(dist);
    cin >> n >> m;
    vi lists;
    forn(i, n)
    {
        cin >> ans1;
        forn(j, ans1) {
            cin >> k;
            k--;
            graph[i].pb(k);
        }
        if (ans1 == 0)
        {
            lists.pb(i);
        }
    }
    cin >> s11;
    s11--;
    bfs(s11);
    if (lists.sz == 0)
    {
        cout << "Draw";
        return 0;
    }
    int have_double_colored = 0;
    int have_black = 0;
    int way_we_go = -1;
    dfs(s11);
    for (int i = 0; i < lists.sz; i++)
    {
        int z = lists[i];
        if (color[z].sz == 0)
            continue;
        if (color[z].sz == 1)
        {
            if (*color[z].begin() == 0)
            {
                have_black = 1;
                way_we_go = z;
            }
        }
        else
        {
            if (*color[z].begin() == 0)
            {
                have_black = 1;
                way_we_go = z;
            }
        }
    }
    if (have_black == 1)
    {
        cout << "Win\n";
        vector<int> way;
        int color_love_me_now = 1;
        while(way_we_go != s11 || way.size() % 2 == 0)
        {
            way.pb(way_we_go);
            int prestige = -1;
            //cout << way_we_go << endl;
            //cout << color[way_we_go].sz;
                //cout << pre[4].sz << endl;
                for (int i = 0; i < pre[way_we_go].sz; i++)
                {
                    int yy = pre[way_we_go][i];
                    //cout << yy << endl ;
                    if ((color[yy].sz == 2) || *color[yy].begin() == color_love_me_now)
                    {
                        prestige = yy;
                        break;
                    }
                }
            way_we_go = prestige;
            color_love_me_now = 1 - color_love_me_now;
            //if (prestige == -1)
            //    return 0;
            //cout << prestige << " " << endl;
        }
        cout << s11 + 1 << " ";
        for (int i = 0; i < way.sz; i++)
        {
            cout << way[way.sz - 1 - i] + 1 << " ";
        }
    }
    else
    if (cicl == 1)
    {
        cout << "Draw";
    }
    else
    {
        cout << "Lose";
    }
}