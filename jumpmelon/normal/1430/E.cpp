#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 200000;
char S[MAXN + 1];
int n, P[MAXN], C[MAXN + 1];
vector<int> A[26];

int query(int i)
{
    int s = 0;
    i++;
    while (i)
    {
        s += C[i];
        i -= i & -i;
    }
    return s;
}

void update(int i, int x)
{
    i++;
    while (i <= n)
    {
        C[i] += x;
        i += i & -i;
    }
}

int main()
{
#ifdef JDEBUG
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%s", S);
    for (int i = 0; i < n; i++)
        A[S[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++)
    {
        int m = (int)A[i].size();
        for (int j = 0; j < m; j++)
            P[A[i][j]] = n - A[i][m - j - 1] - 1;
    }
    big ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += query(P[i]);
        update(P[i], 1);
    }
    printf("%lld\n", ans);
}