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

const int maxn = 200 * 1000;

vi g[maxn];
int par[maxn];

void dfs(int x, int y)
{
    par[x] = y;
    for (int i = 0; i < sz(g[x]); ++i)
        if (par[g[x][i]] == -1)
            dfs(g[x][i], x);
}

int main()
{
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    r1--, r2--;
    for (int i = 0; i < n; ++i)
    {
        if (i == r1) continue;
        int x;
        scanf("%d", &x);
        x--;
        g[x].pb(i);
        g[i].pb(x);
    }
    memset(par, -1, sizeof(par));
    dfs(r2, -2);
    for (int i = 0; i < n; ++i)
        if (i != r2)
            printf("%d ", par[i] + 1);
    printf("\n");
    return 0;
}