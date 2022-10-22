#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int u=min(a,x);
    a-=u;
    x-=u;
    u=min(b,y);
    b-=u;
    y-=u;
    if(x+y>c)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;


    }

    return 0;

}