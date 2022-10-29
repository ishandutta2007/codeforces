#include <bits/stdc++.h>

using namespace std;

int main()
{

    long s,x1,x2,t1,t2,p,d,u1=0,u2=0,u3=0,u4=0;
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    u1=abs(x1-x2)*t2;
    if((x2-x1)*d>0)
    {
        if(d==1)
        {
            if(p<=x1) u2=(x2-p)*t1;
            else u2=(2*s-p+x2)*t1;
        }
        else
        {
            if(p>=x1) u2=(p-x2)*t1;
            else u2=(p+2*s-x2)*t1;
        }
    }
    else
    {
        if(d==1)
        {
            u2=(2*s-p-x2)*t1;
        }
        else
        {
            u2=(p+x2)*t1;
        }
    }
    cout<<min(u1,u2);
    return 0;
}