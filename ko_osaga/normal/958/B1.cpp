#include<bits/stdc++.h>
int fuck[10101];
int main()
{
    int N; scanf("%d", &N);
    for(int i=0;i<2*N-2; ++i)
    {
        int a; scanf("%d", &a);
        fuck[a]++;
    }
    int ans = 0;
    for(int i=0; i<=N; ++i)
        if(fuck[i] == 1) ++ans;
    printf("%d\n", ans);
    return 0;
}