#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int maxn = 218 * 1000;

vi g[maxn], rg[maxn];
int t[maxn];

bool u1[maxn], u2[maxn];

void dfs1(int x) {
    u1[x] = true;
    for (int i = 0; i < sz(g[x]); ++i) {
        int y = g[x][i];
        if (t[y] == 1) cerr << "Botva 1\n";
        if (!u1[y]) dfs1(y);
    }
}

void dfs2(int x) {
    u2[x] = true;   
    for (int i = 0; i < sz(rg[x]); ++i) {       
        if (t[x] == 1)  cerr << "Botva 2\n";
        int y = rg[x][i];       
        if (!u2[y]) dfs2(y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        if (t[y] != 1) {
            g[x].pb(y);
            rg[y].pb(x);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!u1[i] && t[i] == 1) dfs1(i);
        if (!u2[i] && t[i] == 2) dfs2(i);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", (u1[i] && u2[i]) ? 1 : 0);
    return 0;
}