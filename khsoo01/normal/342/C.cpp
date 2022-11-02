#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int x=1,y;
double r,h,sq3=1.73205080757;
int main()
{
    scanf("%lf%lf",&r,&h);
    if(h-sq3*r/2>=0)
    x=(h-sq3*r/2)/r*2+3;
    if(h-r/2>=0)
    y=(h-r/2)/r*2+2;
    printf("%d",max(x,y));
}