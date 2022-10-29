// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
int n, H[N], P[N];
vector < int > Adj[N];
inline pair < int , int > Query(vector < int > vec)
{
    printf("? %d", (int)vec.size());
    for (int i : vec)
        printf(" %d", i);
    printf("\n");
    fflush(stdout);
    int v, d;
    scanf("%d%d", &v, &d);
    assert(v != -1 && d != -1);
    return make_pair(v, d);
}
void DFS(int v, int p = 0)
{
    for (int u : Adj[v])
        if (u != p)
            P[u] = v,
            H[u] = H[v] + 1,
            DFS(u, v);
}
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            Adj[i].clear(), H[i] = P[i] = 0;
        for (int i = 1; i < n; i ++)
        {
            int v, u;
            scanf("%d%d", &v, &u);
            Adj[v].push_back(u);
            Adj[u].push_back(v);
        }
        vector < int > vec;
        for (int i = 1; i <= n; i ++)
            vec.push_back(i);
        auto rs = Query(vec);
        int root = rs.first;
        int d = rs.second;
        DFS(root);

        int le = (d + 1) / 2 - 1, ri = min(d, * max_element(H + 1, H + n + 1)) + 1, md;
        while (ri - le > 1)
        {
            md = (le + ri) >> 1;
            vec.clear();
            for (int i = 1; i <= n; i ++)
                if (H[i] == md)
                    vec.push_back(i);
            rs = Query(vec);
            if (rs.second == d)
                le = md, root = rs.first;
            else
                ri = md;
        }

        H[root] = P[root] = 0;
        DFS(root);
        vec.clear();
        for (int i = 1; i <= n; i ++)
            if (H[i] == d)
                vec.push_back(i);
        rs = Query(vec);
        assert(rs.second == d);
        printf("! %d %d\n", root, rs.first);
        fflush(stdout);
        char ss[10];
        scanf("%s", &ss);
        assert(ss[0] == 'C');
    }
    return 0;
}