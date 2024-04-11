#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    queue <int> Q;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        Q.push(a);
    }
    int ans = 0;
    while(!Q.empty())
    {
        int x = k;
        int a = Q.front();
        while(a <= x)
        {
            x -= a;
            Q.pop();
            if(Q.empty())
                break;
            a = Q.front();
        }
        ans++;
    }
    printf("%d\n", ans);
}