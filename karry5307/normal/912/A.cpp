#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,z,h,l,sum,yel,blu;
int main()
{
    cin>>h>>l>>x>>y>>z;
    yel=2*x+y;
    blu=y+3*z;
    if(yel>h)
    {
        sum+=yel-h;
    }
    if(blu>l)
    {
        sum+=blu-l;
    }
    cout<<sum;
}