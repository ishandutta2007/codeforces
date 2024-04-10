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
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define th third
#define a_ 1000000007
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
ll n, m, k, l, r, x, y, t, ans, k1, k2, k3;
string s;
int a[6][6];
//___________VARIABLES____________

void check(int b, int c, int d)
{
    t = 0;
    for (int i = 0; i < 6; i++)
    {
        if (a[b][i] == k1 || k1 == -1)
            {t += 1; break;}
    }
    for (int i = 0; i < 6; i++)
    {
        if (a[c][i] == k2 || k2 == -1)
            {t += 2; break;}
    }
    for (int i = 0; i < 6; i++)
    {
        if (a[d][i] == k3)
        {    t += 3;
            break;
    }
    }
    //cout << t << endl;
    if (t == 6)
    {
        x = 1;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 6; j++)
           cin >> a[i][j];
    }
    for (int i = n + 1; i <= 3; i++)
    {
        for (int j = 0; j < 6; j++)
        a[i][j] = -1;
    }
    for (int i = 1; i < 1000; i++)
    {
        k1 = i / 100;
        k2 = i / 10 % 10;
        k3 = i % 10;
        if (k1 == 0)
          {
              k1 = -1;
              if (k2 == 0)
              k2 = -1;
          }
          
        //cout << k1 << " "<< k2 << " "<< k3 << endl;
        x = 0;
        check(1, 2, 3);
        check(1, 3, 2);
        check(2, 3, 1);
        check(2, 1, 3);
        check(3, 2, 1);
        check(3, 1, 2);
        if (x == 0)
        {
            cout << i - 1;
            return 0;
        }
    }
}