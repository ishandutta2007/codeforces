#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int A[MAXN + 1], Nxt[MAXN + 1], Vis[MAXN + 1];
stack<int> S;
vector<pair<int, int>> Ans;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = n; i >= 1; i--)
        if (A[i] == 1)
            S.push(i);
    for (int i = n - 1; i >= 1; i--)
        if (A[i + 1] && (!Nxt[i + 1] || A[i + 1] != 1))
            Nxt[i] = i + 1;
        else
            Nxt[i] = Nxt[i + 1];
    int m = 1;
    for (int i = 1; i <= n; i++)
        if (A[i] == 3)
        {
            if (!Nxt[i])
                goto fail;
            Ans.push_back({i, m});
            Ans.push_back({Nxt[i], m++});
            Vis[Nxt[i]] = 1;
        }
    for (int i = 1; i <= n; i++)
        if (A[i] == 1)
        {
            if (Vis[i] != 2)
                Ans.push_back({i, m++});
        }
        else if (A[i] == 2)
        {
            while (!S.empty() && (S.top() < i || Vis[S.top()]))
                S.pop();
            if (S.empty())
                goto fail;
            Ans.push_back({i, m});
            Ans.push_back({S.top(), m++});
            Vis[S.top()] = 2;
            S.pop();
        }
    printf("%d\n", (int)Ans.size());
    for (auto &&p : Ans)
        printf("%d %d\n", p.second, p.first);
    return 0;
fail:
    puts("-1");
    return 0;
}