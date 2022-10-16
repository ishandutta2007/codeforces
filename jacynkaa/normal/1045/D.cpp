#include <bits/stdc++.h>
using namespace std;

typedef double ld;

const int N = 1e5+5;

vector<int> G[N];

ld prob[N];
ld child_sum[N];
int parent[N];

void dfs(int v);

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
    {
        scanf("%lf", &prob[i]);
        child_sum[i] = 0.0;
    }

    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        a++;
        b++;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    prob[0] = 1.0;
    parent[1] = 0;
    dfs(1);
    child_sum[0] = 1.0 - prob[1];

    ld res = 0.0;
    for(int i=1;i<=n;i++)
    {
        res += (1.0-prob[i])*prob[parent[i]];
    }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int v;
        ld new_prob;

        scanf("%d%lf", &v, &new_prob);
        v++;

        res -= child_sum[v] * prob[v];
        res -= (1.0 - prob[v]) * prob[parent[v]];

        child_sum[parent[v]] -= (1.0 - prob[v]);
        prob[v] = new_prob;
        child_sum[parent[v]] += (1.0 - prob[v]);

        res += child_sum[v] * prob[v];
        res += (1.0 - prob[v]) * prob[parent[v]];
    
        printf("%lf\n", res);
    }
}

void dfs(int v)
{
    for(auto z : G[v])
    {
        if(z == parent[v])
        {
            continue;
        }

        parent[z] = v;
        dfs(z);

        child_sum[v] += (1.0 - prob[z]);
    }
}