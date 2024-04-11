#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, a,b,c,d,x,y,x1,y1,x2,y2;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
        if ((x1==x2) and ((a!=0) or (b!=0)))
            cout<<"No\n";
        else if ((y1==y2) and ((c!=0) or (d!=0)))
            cout<<"No\n";
        else
        if ((x-a+b>=x1) and (x-a+b<=x2) and (y-c+d>=y1) and (y-c+d<=y2))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

}