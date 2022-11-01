#include <iostream>
#include<cstdio>

using namespace std;

double a,d,x,y,k;
int t,n;

int main()
{
    cin>>a>>d>>n;
    while(d>=4*a)
        d-=4*a;
    x=0;
    y=0;
    t=0;
    for(int i=0;i<n;i++)
    {
        k=d;
        while(k>0)
        {
            if(t==0)
            {
               if(a-x>k)
               {
                   x+=k;
                   break;
               }
               else
               {
                   t++;
                   k-=a-x;
                   x=a;
               }
            }
            if(t==1)
            {
               if(a-y>k)
               {
                   y+=k;
                   break;
               }
               else
               {
                   t++;
                   k-=a-y;
                   y=a;
               }
            }
            if(t==2)
            {
               if(x>k)
               {
                   x-=k;
                   break;
               }
               else
               {
                   t++;
                   k-=x;
                   x=0;
               }
            }
            if(t==3)
            {
               if(y>k)
               {
                   y-=k;
                   break;
               }
               else
               {
                   t=0;
                   k-=y;
                   y=0;
               }
            }
        }
        printf("%lf %lf\n",x,y);
    }
}