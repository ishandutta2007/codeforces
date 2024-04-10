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
#define f(i, n) for (int i = 0; i < n; i++)
#define sz size()
#define all(x) x.begin(),x.end()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
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
const int MOD = 1000000007;
const ll INF = 1e18 + 2;
const int LIT = 505;
const int BIG = 200001;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
ll st_10[10] = {1, 10, 100, 1000, 10000, 1000000, 10000000, 100000000, 1000000000};
//___________BAZE_________________
ll n, m, k, l, r, x, y, xk, yk, how, can;
ll ans = 1;
map<int, vector<int> > x_y;
map<int, vector<int> > y_x;
map<pii, int> indeee;
pii tap[100003];
int used[100003];
map<int, bool> used_x;
map<int, bool> used_y;
int cicles = 0;
int gg;
//___________VARIABLES____________

int binary_s(int p, vector<int>& kk)
{
    return lower_bound(all(kk), p) - kk.begin();
}

void dfs(int i, int flag, int prre_)
{
    used[i] = flag;
    int x1 = tap[i].fi;
    int y1 = tap[i].se;
    if (used_x[x1] == 0)
    {
        gg++;
        used_x[x1]++;
    }
    if (used_y[y1] == 0)
    {
        gg++;
        used_y[y1]++;
    }
    //cout << x1 << " " << y1 << endl;
    //cout << x1 << " " << y1 << endl;
    int position1 = binary_s(y1, x_y[x1]);
    int position2 = binary_s(x1, y_x[y1]);
    //cout << position1 << " //  " << x_y[x1].sz - 1 << endl;
    if (position1 < x_y[x1].sz - 1)
    {
        int y2_ = x_y[x1][position1 + 1];
        int ind = indeee[{x1, y2_}];
        if (used[ind] == 0)
        {
            dfs(ind, flag, i);
        }
        else
        {
            if (prre_ != ind)
                cicles = 1;
        }
    }
    if (position2 < y_x[y1].sz - 1)
    {
        int x2 = y_x[y1][position2 + 1];
        int ind = indeee[{x2, y1}];
        if (used[ind] == 0)
        {
            dfs(ind, flag, i);
        }
        else
        {
            if (prre_ != ind)
                cicles = 1;
        }
    }
    if (position1 > 0)
    {
        int y2_ = x_y[x1][position1 - 1];
        int ind = indeee[{x1, y2_}];
        if (used[ind] == 0)
        {
            dfs(ind, flag, i);
        }
        else
        {
            if (prre_ != ind)
                cicles = 1;
        }
    }
    if (position2 > 0)
    {
        int x2 = y_x[y1][position2 - 1];
        int ind = indeee[{x2, y1}];
        if (used[ind] == 0)
        {
            dfs(ind, flag, i);
        }
        else
        {
            if (prre_ != ind)
                cicles = 1;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        tap[i].fi = x;
        tap[i].se = y;
    }
    sort(tap, tap + n);
    for (int i = 0; i < n; i++)
    {
        indeee[{tap[i].fi, tap[i].se}] = i;
        x_y[tap[i].fi].pb(tap[i].se);
        y_x[tap[i].se].pb(tap[i].fi);
    }
    for (auto i = y_x.begin(); y_x.end() != i; i++)
    {
        sort(all(i->se));
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        cicles = 0;
        gg = 0;
        if (used[i] == 0)
        {
            dfs(i, flag, -1);
            flag++;
            //cout << cicles << endl;
            //cout << gg << " " << cicles << endl;
            int saved_ans = 1;
            if (cicles == 1)
            {
                for (int i = 0; i < gg; i++)
                {
                    saved_ans = (saved_ans * 2) % MOD;
                }
            }
            else
            {
                for (int i = 0; i < gg; i++)
                {
                    saved_ans = (saved_ans * 2) % MOD;
                }
                saved_ans--;
            }
            ans = (ans * saved_ans) % MOD;
        }
    }
    cout << ans;
}