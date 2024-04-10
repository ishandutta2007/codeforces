/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int x, y, x1, x2, y1, y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;

    if((a!=0 || b!=0) && x1==x2) return false;
    if((c!=0 || d!=0) && y1==y2) return false;

    x = (x-a+b);
    y = (y-c+d);

    if(x<x1 || x>x2) return false;
    if(y<y1 || y>y2) return false;

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}