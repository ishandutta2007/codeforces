#include <iostream>
#include<algorithm>

using namespace std;

long long a1,a2,b,b1,b2,x,y,t11,t12,t21,t22;

int main()
{
    cin>>a1>>b1>>a2>>b2;
    x=a1*b1;
    y=a2*b2;
    while(x%2==0)
    {
        t11++;
        x/=2;
    }
    while(x%3==0)
    {
        t12++;
        x/=3;
    }
    while(y%2==0)
    {
        t21++;
        y/=2;
    }
    while(y%3==0)
    {
        t22++;
        y/=3;
    }
    //cout<<x<<" "<<y<<endl;
    if(x!=y)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(t12>=t22)
    {
        for(int i=0;i<t12-t22;i++)
        {
            if(a1%3==0)
                a1=a1/3*2;
            else
                b1=b1/3*2;
        }
        t11+=t12-t22;
        cout<<t12-t22+max(t11,t21)-min(t11,t21)<<endl;
        while(t11>t21)
        {
            if(a1%2==0)
                a1/=2;
            else
                b1/=2;
            t11--;
        }
        while(t11<t21)
        {
            if(a2%2==0)
                a2/=2;
            else
                b2/=2;
            t21--;
        }
    }
    else
    {
        for(int i=0;i<t22-t12;i++)
        {
            if(a2%3==0)
                a2=a2/3*2;
            else
                b2=b2/3*2;
        }
        t21+=t22-t12;
        cout<<t22-t12+max(t11,t21)-min(t11,t21)<<endl;
        while(t11>t21)
        {
            if(a1%2==0)
                a1/=2;
            else
                b1/=2;
            t11--;
        }
        while(t11<t21)
        {
            if(a2%2==0)
                a2/=2;
            else
                b2/=2;
            t21--;
        }
    }
    cout<<a1<<" "<<b1<<"\n"<<a2<<" "<<b2<<"\n";
}