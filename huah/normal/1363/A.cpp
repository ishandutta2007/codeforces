#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,a=0,b=0;scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            if(x&1) b++;
            else a++;
        }
        if(!b) printf("No\n");
        else if(!a&&x%2==0) printf("No\n");
        else if(b%2==0&&x==n) printf("No\n");
        else printf("Yes\n");
    }
}