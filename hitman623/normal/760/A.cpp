#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,d;
    cin>>m>>d;
    if(m==2)
    {
        if(d==1) cout<<4;
        else cout<<5;
    }
    else
    {
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        {
            if(d<=5) cout<<5;
            else cout<<6;
        }
        else
        {
            if(d<=6) cout<<5;
            else cout<<6;
        }
    }
    return 0;
}