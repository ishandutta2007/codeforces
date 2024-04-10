#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;

li n, d;
li a[2050];
li ans;

int main()
{
    cin >> n >> d;
    forn(i, n) cin >> a[i];
    for1(i, n - 1) {
        if (a[i] > a[i - 1]) continue;
        li t = a[i - 1] - a[i];
        ans += t / d;
        a[i] += (t / d) * d;
        a[i] += d;
        ans++;
    }
    cout << ans << endl;
    return 0;
}