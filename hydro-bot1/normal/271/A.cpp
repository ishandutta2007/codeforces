// Hydro submission #6253c9bf48f78301327920e0@1649658303793
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y,a,b,c,d;
    cin>>y;
    while(y++)
    {
        a=y%10;
        b=y/10%10;
        c=y/100%10;
        d=y/1000;
        if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
        {
            printf("%d\n",y);
            return 0;
        }
    }
    return 0;
}