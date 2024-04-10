#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;

bool vis[MAXN*2];

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if (!vis[x]) vis[x]=true;
        else
            for (int j=x+1;;j++)
                if (!vis[j])
                {
                    vis[j]=true;
                    ans+=j-x;
                    break;
                }
    }
    printf("%d",ans);
    return 0;
}