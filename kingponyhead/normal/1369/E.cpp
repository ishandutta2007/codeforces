// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, A[N], B[N], C[N], D[N], M[N], MR[N];
vector < int > Ad[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++)
        scanf("%d", &C[i]);
    for (int i = 0; i < m; i ++)
        scanf("%d%d", &A[i], &B[i]),
        A[i] --, B[i] --,
        Ad[A[i]].push_back(i),
        Ad[B[i]].push_back(i);
    queue < int > qu;
    for (int i = 0; i < n; i ++)
    {
        D[i] = (int)Ad[i].size();
        if (C[i] >= D[i])
            M[i] = 1, qu.push(i);
    }
    vector < int > R;
    while (qu.size())
    {
        int i = qu.front();
        qu.pop();
        for (int a : Ad[i])
        {
            if (MR[a])
                continue;
            MR[a] = 1;
            R.push_back(a);
            int j = A[a] ^ B[a] ^ i;
            if (M[j])
                continue;
            D[j] --;
            if (C[j] >= D[j])
                M[j] = 1, qu.push(j);
        }
    }
    if (R.size() < m)
        return !printf("DEAD\n");
    reverse(R.begin(), R.end());
    printf("ALIVE\n");
    for (int i : R)
        printf("%d ", i + 1);
    printf("\n");
    return 0;
}