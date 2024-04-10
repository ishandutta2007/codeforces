#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 218 * 1000;

vector<ii> g[maxn];

bool cmp(pair<double, double> p, pair<double, double> q) {
    return p.first * q.second - p.second * q.first < 0;
}

pair<double, pair<double, int> > dfs(int x, int p = -1) {
    double res = 0;
    int cnt = 1;
    vector<pair<double, double> > v;
    for (int i = 0; i < sz(g[x]); ++i) {
        int y = g[x][i].first;
        if (y == p) continue;
        pair<double, pair<double, int> > p = dfs(y, x);
        res += p.first;
        res += (p.second.second + 0.) * (g[x][i].second + 0.); 
        cnt += p.second.second;
        v.pb(pair<double, double>(2. * g[x][i].second + p.second.first + 0., p.second.second + 0.));
    }
    sort(all(v), cmp);
    double T = 0.0;
    for (int i = 0; i < sz(v); ++i) {
        res += T * v[i].second;
        T += v[i].first;
    }
    return mp(res, mp(T, cnt));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x, --y;
        g[x].pb(ii(y, z));
        g[y].pb(ii(x, z));
    }
    pair<double, pair<double, int> > res = dfs(0);
    printf("%.10lf\n", res.first / (n - 1.));
    return 0;
}