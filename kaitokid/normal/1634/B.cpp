#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ans[]={"Alice","Bob"};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y,a,u=0;
        cin>>n>>x>>y;
        x%=2;
        y%=2;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a%2)u=1-u;
        }
        if(x!=y)u=1-u;
        cout<<ans[u]<<endl;

               }
    return 0;
}