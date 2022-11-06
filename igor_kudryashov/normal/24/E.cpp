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
#include <ctime>
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
const double PI = 3.1415926535897932384626433832795;

int n;
pt a[500005];

bool can (double t) {
    double rg = -1e20;
    forn(i, n)
        if (a[i].second < 0) {
            double lf = a[i].first + a[i].second * t;
            if (lf - EPS < rg) return true;
        } else {
            double nrg = a[i].first + a[i].second * t;
            if (nrg > rg) rg = nrg;
        }
    return false;

}

bool bad () {
    int k = 0;
    while (k < n && a[k].second < 0) k++;
    for (int i = k + 1; i < n; i++)
        if (a[i].second < 0) return false;
    return true;
}

int main()
{
    cin >> n;
    forn(i, n) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    if (bad()) {
        cout << -1 << endl;
        return 0;
    }
    double lf = 0, rg = INF;
    forn(i, 300) {
        double mid = (lf + rg) / 2;
        if (can(mid)) rg = mid; else lf = mid;
    }
    cout.precision(10);
    cout << fixed << (lf + rg) / 2 << endl;
    return 0;
}