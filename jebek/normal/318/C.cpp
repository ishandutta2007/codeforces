#include <iostream>

using namespace std;

int main()
{
    long long x,y,m,n=0,a;
    cin>>x>>y>>m;
    if(x>y)
    {
        x=x+y;
        y=x-y;
        x=x-y;
    }
    if(m>0 && y<=0)
        cout<<"-1";
    else if(m==0 && y<0)
        cout<<"-1";
    else if(m<0 && y<m)
        cout<<"-1";
    else
    {
        if(y>=m)
            n=0;
        else
        {
            a=y-x;
            a=a/y;
            n=a;
            x=n*y+x;
            while(y<m)
            {
                n++;
                a=y;
                y=x+y;
                x=a;
                if(x>y)
                {
                    x=x+y;
                    y=x-y;
                    x=x-y;
                }
            }
        }
        cout<<n;
    }
}