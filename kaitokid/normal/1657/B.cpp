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
        ll n,b,x,y;
        cin>>n>>b>>x>>y;
        ll res=0,u=0;
        for(int i=0;i<n;i++)
        {
            if(u+x<=b)u+=x;else u-=y;
            res+=u;
        }
        cout<<res<<endl;
    }
}