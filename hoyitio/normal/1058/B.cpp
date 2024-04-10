#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        bool ans = true;
        int x0,y0,x1,y1;
        x0 = 0;y0 = d;x1 = d;y1 = 0;
        if((y0-y1)*x+(x1-x0)*y+(x0*y1-x1*y0)<0){ans = false;}
        x0 = d;y0 = 0;x1 = n;y1 = n-d;
        if((y0-y1)*x+(x1-x0)*y+(x0*y1-x1*y0)<0){ans = false;}
        x0 = 0;y0 = d;x1 = n-d;y1 = n;
        if((y0-y1)*x+(x1-x0)*y+(x0*y1-x1*y0)>0){ans = false;}
        x0 = n-d;y0 = n;x1 = n;y1 = n-d;
        if((y0-y1)*x+(x1-x0)*y+(x0*y1-x1*y0)>0){ans = false;}
        ans?printf("YES\n"):printf("NO\n");
    }
    return 0;
}