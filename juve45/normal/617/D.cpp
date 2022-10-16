#include <bits/stdc++.h>

using namespace std;

bool isBetween(int y, int s1, int s2)
{
    if(min(s1, s2)<=y && max(s1, s2)>=y)
        return true;
    return false;
    }

int x[5];
int y[5];
int main()
{
cin>>x[1]>>y[1];
cin>>x[2]>>y[2];
cin>>x[3]>>y[3];


if(x[1]==x[2]&& x[2]==x[3])
{
    cout<<1<<'\n';
    return 0;
}
if(y[1]==y[2] && y[2]==y[3])
{
    cout<<1<<'\n';
    return 0;
}

if((x[1]==x[3] || x[2]==x[3])&&  isBetween(y[3],y[1],y[2]))
{
    cout<<2<<'\n';
    return 0;
}
if((x[3]==x[1]||x[1]==x[2]) &&  isBetween(y[1],y[3],y[2]))
{
    cout<<2<<'\n';
    return 0;
}
if((x[2]==x[3]||x[1]==x[2]) &&  isBetween(y[2],y[1],y[3]))
{
    cout<<2<<'\n';
    return 0;
}

swap(x[1], y[1]);
swap(x[2], y[2]);
swap(x[3], y[3]);
if((x[1]==x[3] || x[2]==x[3])&&  isBetween(y[3],y[1],y[2]))
{
    cout<<2<<'\n';
    return 0;
}
if((x[3]==x[1]||x[1]==x[2]) &&  isBetween(y[1],y[3],y[2]))
{
    cout<<2<<'\n';
    return 0;
}
if((x[2]==x[3]||x[1]==x[2]) &&  isBetween(y[2],y[1],y[3]))
{
    cout<<2<<'\n';
    return 0;
}


cout<<3<<'\n';
    return 0;
}