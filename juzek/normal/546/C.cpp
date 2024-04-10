#include <bits/stdc++.h>
using namespace std;

queue<int>Q1;
queue<int>Q2;


int main()
{
    int N;
    scanf("%d",&N);
    int k1,k2;
    scanf("%d",&k1);
    int a,b;
    for (int i = 0;i < k1;i++)
    {
        scanf("%d",&a);
        Q1.push(a);
    }
    scanf("%d",&k2);
    for (int i = 0;i < k2;i++)
    {
        scanf("%d",&a);
        Q2.push(a);
    }
    int il = 0;
    while (!Q1.empty() && !Q2.empty() && il < 500)
    {
        a = Q1.front();
        b = Q2.front();
        Q1.pop();
        Q2.pop();
        if (a > b)
        {
            Q1.push(b);
            Q1.push(a);
        }
        else
        {
            Q2.push(a);
            Q2.push(b);
        }
        il++;
    }
    if (il == 500)
        printf("-1");
    else
    {
        printf("%d ",il);
        if (Q1.empty())
            printf("2");
        else
            printf("1");
    }
    return 0;
}