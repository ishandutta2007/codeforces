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

int main()
{
    li n, m, a;
    cin >> n >> m >> a;
    li ans = 0;
    ans += n / a;
    if (n % a) ans++;
    m -= a;
    if (m > 0) {
        li t = ans;
        ans += (m / a) * t;
        if (m % a) ans += t;
    }
    cout << ans << endl;
    return 0;
}