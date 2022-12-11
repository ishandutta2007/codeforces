#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (x1==x2)
    {
        int d=abs(y1-y2);
        x3=x4=x1+d;
        y3=y1;y4=y2;
    }
    else if (y1==y2)
    {
        int d=abs(x1-x2);
        y3=y4=y1+d;
        x3=x1;x4=x2;
    }
    else 
    {
        x3=x1;y3=y2;
        x4=x2;y4=y1;
        if (abs(y1-y3)!=abs(x1-x4)) 
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d %d %d %d",x3,y3,x4,y4);
    return 0;
}