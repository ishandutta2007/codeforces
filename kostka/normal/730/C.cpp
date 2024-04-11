#include <bits/stdc++.h>
using namespace std;

struct store
{
    int c, k, p;
};

bool operator<(store a, store b)
{
    return a.p < b.p;
}

const int N = 5001;
int dist[N][N];
vector<int> g[N];
store s[N];
int n, m, w;

bool check(int d, int g, int r, int a)
{
    for(int i = 0; i < w; i++)
        if(dist[g][s[i].c] <= d)
        {
            //printf("%d %d %d\n", g, r, a);
            int k = min(s[i].k, r);
            if(1LL * s[i].p * k > a) return false;
            a -= s[i].p * k;
            r -= k;
            //printf("%d %d %d\n", g, r, a);
            if(r == 0) return true;
        }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d", &w);
    for(int i = 0; i < w; i++)
        scanf("%d %d %d", &s[i].c, &s[i].k, &s[i].p);
    sort(s, s + w);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            dist[i][j] = N;
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int v = q.front(), d = dist[i][v];
            q.pop();
            for(int u: g[v])
                if(dist[i][u] == N)
                {
                    dist[i][u] = d + 1;
                    q.push(u);
                }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int g, r, a;
        scanf("%d %d %d", &g, &r, &a);
        int A = 0, B = n, C;
        while(A < B)
        {
            C = (A + B) / 2;
            if(check(C, g, r, a)) B = C;
            else A = C + 1;
        }
        if(!check(A, g, r, a)) puts("-1");
        else printf("%d\n", A);
    }
}