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
vector <pt> g[105];

int go (int v, int pr, int co) {
    if (v == 0) return co;
    forn(i, g[v].size()) {
        int to = g[v][i].first, c = g[v][i].second;
        if (to != pr) return go(to, v, co + c);
    }
    throw;
}

int main()
{
    cin >> n;
    forn(i, n) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        g[a].pb(mp(b, 0));
        g[b].pb(mp(a, c));
    }
    int t1 = go(g[0][0].first, 0, g[0][0].second);
    int t2 = go(g[0][1].first, 0, g[0][1].second);
    cout << min(t1, t2) << endl;
    return 0;
}