#include <bits/stdc++.h>
using namespace std;
int n, m, S, bel[200010], lst[200010];
vector<int> G[200010];
int main()
{
    vector<int> st;
    scanf("%d %d %d", &n, &m, &S);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        if (y == S)
            continue;
        if (x != S)
            G[x].push_back(y);
        else
            st.push_back(y);
    }
    for (auto x : st)
        bel[x] = x;
    queue<int> Q;
    for (auto x : st)
        Q.push(x);
    int nx = 0, ny = 0;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (auto to : G[x])
        {
            if (bel[to] == bel[x])
                continue;
            if (bel[to])
            {
                nx = to;
                ny = x;
                break;
            }
            bel[to] = bel[x];
            lst[to] = x;
            Q.push(to);
        }
        if (nx)
            break;
    }
    if (!nx)
        puts("Impossible");
    else
    {
        puts("Possible");
        vector<int> Ans1, Ans2;
        Ans1.push_back(nx);
        Ans2.push_back(nx);
        Ans2.push_back(ny);
        while (lst[ny])
        {
            ny = lst[ny];
            Ans2.push_back(ny);
        }
        while (lst[nx])
        {
            nx = lst[nx];
            Ans1.push_back(nx);
        }
        Ans1.push_back(S);
        Ans2.push_back(S);
        reverse(Ans1.begin(), Ans1.end());
        reverse(Ans2.begin(), Ans2.end());
        printf("%d\n", (int)Ans1.size());
        for (auto x : Ans1)
            printf("%d ", x);
        puts("");
        printf("%d\n", (int)Ans2.size());
        for (auto x : Ans2)
            printf("%d ", x);
        puts("");
    }
    return 0;
}