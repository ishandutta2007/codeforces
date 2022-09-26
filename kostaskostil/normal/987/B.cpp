#include <bits/stdc++.h>
using namespace std;

#define int long long
int pow(int x, int y)
{
    int ans=1;
    for (int i=1; i<=y; i++)
        ans*=x;
    return ans;
}

main()
{
    int x,y;
    cin>>x>>y;
    if (x==y)
    {
        cout<<"=";
        return 0;
    }
    if (x==1)
    {
        cout<<"<";
        return 0;

    }
    if (y==1)
    {
        cout<<">";
        return 0;
    }
    if ((x<10) and (y<10))
    {
        if (pow(x,y)<pow(y,x))
            cout<<"<";
        else
        if (pow(x,y)==pow(y,x))
            cout<<"=";
        else
            cout<<">";
    }
    else
    {
        if (x<y)
            cout<<">";
        else
            cout<<"<";
    }
    return 0;
}