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
        ll n,m,x,y,a,b;
        cin>>n>>m>>x>>y>>a>>b;
        ll ans1;
        if(a>=x)ans1=a-x;
        else ans1=n-x+n-a;
        ll ans2;

        if(b>=y)ans2=b-y;
        else ans2=m-y+m-b;
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}