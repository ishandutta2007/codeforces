#include <iostream>

using namespace std;

int main()
{
    char a;
    char b;
    char c,d,e;


    int h;
    cin>>h;
    cin>>a>>b>>c>>d>>e;
    a = a-'0';
    b = b-'0';
    d = d-'0';
    e = e-'0';
    if (d>5)
        d=0;
    if (h==24)
    {
        if(a>2)
            a=0;
        if((a==2)&&(b>3))
            a=0;
    }
    if(h==12)
    {
        if(b==0)
            a=1;
        if(b>2)
            a=0;
        if((b==1)||(b==2))
        {
            if((a!=0)&&(a!=1))
                a=0;
        }
    }
    a=a+'0';
    b=b+'0';
    d=d+'0';
    e=e+'0';
    cout<<a<<b<<c<<d<<e;


}