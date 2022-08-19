#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <iterator>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

double p[100005];
int parent[100005];
vector<int> adj[100005];
double psum[100005];

void dfs(int root)
{
    for (auto& e : adj[root])
    {
        if (e == parent[root])
            continue;

        parent[e] = root;
        psum[root] += p[e];

        dfs(e);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &p[i]);
        p[i] = 1 - p[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    parent[0] = -1;

    double ans = 0;

    for (int i = 0; i < n; i++)
        ans += p[i] * (1 - psum[i]);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int v;
        double np;
        scanf("%d %lf", &v, &np);
        np = 1 - np;

        ans -= p[v] * (1 - psum[v]);

        if (v != 0)
        {
            ans += p[parent[v]] * psum[parent[v]];
            psum[parent[v]] -= p[v];
        }
        
        p[v] = np;

        if (v != 0)
        {
            psum[parent[v]] += p[v];
            ans -= p[parent[v]] * psum[parent[v]];
        }

        ans += p[v] * (1 - psum[v]);
        printf("%lf\n", ans);
    }

    return 0;
}