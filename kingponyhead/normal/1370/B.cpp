// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 2019;
int n, A[N];
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d", &n);
        vector < int > V[2];
        for (int i = 0; i < n + n; i ++)
            scanf("%d", &A[i]), V[A[i] & 1].push_back(i + 1);
        if (V[1].size() & 1)
            V[1].pop_back(), V[0].pop_back();
        else if (V[1].size())
            V[1].pop_back(), V[1].pop_back();
        else
            V[0].pop_back(), V[0].pop_back();
        for (int i = 1; i < (int)V[0].size(); i += 2)
            printf("%d %d\n", V[0][i], V[0][i - 1]);
        for (int i = 1; i < (int)V[1].size(); i += 2)
            printf("%d %d\n", V[1][i], V[1][i - 1]);
    }
    return 0;
}