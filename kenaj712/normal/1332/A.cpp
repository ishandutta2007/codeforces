#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a,b,c,d,x,y,x1,y1,x2,y2,x3,y3;
    cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
    x3=x-a+b;
    y3=y-c+d;
    if(x1==x2 && (a!=0 || b!=0))
    {
        cout<<"No"<<'\n';
        return;
    }
    if(y1==y2 && (c!=0 || d!=0))
    {
        cout<<"No"<<'\n';
        return ;
    }
    if(x>= x1 && x<=x2 && x3>= x1 && x3<=x2 && y>= y1 && y<=y2 && y3>= y1 && y3<=y2 )
        cout<<"Yes";
    else
        cout<<"No";
    cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}