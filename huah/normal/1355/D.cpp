#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool vis[N];
int main()
{
    int n,s;scanf("%d%d",&n,&s);
    if(s>=n*2)
    {
        printf("YES\n");
        for(int i=1;i<n;i++)
            printf("%d ",2);
        printf("%d\n",s-(n-1)*2);
        printf("%d\n",1);
        return 0;
    }
    if(n==1)
    {
        if(s==1)
        {
            printf("NO\n");return 0;
        }
        printf("YES\n");
        printf("%d\n",s);
        printf("%d\n",s-1);
        return 0;
    }
    if(s==n||s==n+1)
    {
        printf("NO\n");
        return 0;
    }
    printf("NO\n");
}