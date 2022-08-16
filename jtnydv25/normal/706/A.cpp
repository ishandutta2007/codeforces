#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    double a,b,v;
    cin>>a>>b;
    int n;
    cin>>n;
    int x,y;
    double ans = 1e18;
    for(int i = 0;i<n;i++)
        cin>>x>>y>>v,ans = min(ans,sqrt((a-x)*(a-x)+(b-y)*(b-y))/v);
    cout<<setprecision(10)<<fixed<<ans;
}