/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y;
    cin>>y;

    while(1)
    {
        y++;
        int tmp=y;

        int a,b,c,d;
        a=tmp%10;
        tmp/=10;
        b=tmp%10;
        tmp/=10;
        c=tmp%10;
        tmp/=10;
        d=tmp;

        if(a==b || b==c || c==d || d==a || a==c || b==d)
        {
            continue;
        }
        else
        {
            cout<<y<<endl;
            break;
        }
    }

    return 0;
}