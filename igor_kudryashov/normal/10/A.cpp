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

int n, p1, p2, p3, t1, t2;
int lf[150], rg[150];
int sum;

int get (int k) {
    int res = 0;
    if (k <= t1) return k * p1; else {
        res += t1 * p1;
        k -= t1;
    }
    if (k <= t2) {
        return res + k * p2;
    } else {
        res += t2 * p2;
        k -= t2;
    }
    return res + k * p3;
}

int main()
{
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    forn(i, n) {
        cin >> lf[i] >> rg[i];
    }
    sum = (rg[0] - lf[0]) * p1;
    for1(i, n - 1) {
        int k = get(lf[i] - rg[i - 1]);
        sum += (rg[i] - lf[i]) * p1 + k;
    }
    cout << sum << endl;
    return 0;
}