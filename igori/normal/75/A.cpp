#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;
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
#define file_(filename) freopen(""filename".in", "r", stdin); freopen(""filename".out", "w", stdout);
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
//___________BAZE_________________
ll n, m, k, l, r, x, y;
int a, b;
ll summ, ans;
int arr[BIG];
int bill[BIG];
int cova[BIG];
int dogg[BIG];
//___________VARIABLES____________

int main()
{
    cin >> a >> b;
    n = a + b;
    int i = 0;
    while (a > 0)
    {
        arr[i] = a % 10;
        a /= 10;
        if (arr[i] != 0)
            i++;
    }
    int j = 0;
    while (b > 0)
    {
        bill[j] = b % 10;
        b /= 10;
        if (bill[j] != 0)
            j++;
    }
    int memory = 0;
    for (int k = 0; k < max(i, j); k++)
    {
        cova[k] = (arr[k] + bill[k] + memory) % 10;
        memory = (arr[k] + bill[k] + memory) / 10;
        //cout << cova[k];
    }
    if (memory == 1)
    {
        cova[max(i, j)] = 1;
        //cout << 1;
    }
    int u = 0;
    while (n > 0)
    {
        dogg[u] = n % 10;
        n /= 10;
        if (dogg[u] != 0)
            u++;
    }
    for (int x = 0; x < u; x++)
    {
        if (dogg[x] != cova[x])
        {
            r_NO
        }
    }
    r_YES
}