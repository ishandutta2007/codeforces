#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,x,y,x1,y1,x2,y2;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
        if(!(x>=x1&&x<=x2&&y>=y1&&y<=y2))
        {
            printf("No\n");
            continue;
        }
        x=x-a+b;
        y=y-c+d;
        if(!(x>=x1&&x<=x2&&y>=y1&&y<=y2)) printf("No\n");
        else
        {
            if(x1==x2&&(a||b)||y1==y2&&(c||d)) printf("No\n");
            else printf("Yes\n");
        }
    }
}