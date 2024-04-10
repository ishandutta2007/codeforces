#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>m;
    int l=x,r=x;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        int d=max(l,u);
        int g=min(r,v);
        if(g>=d){l=min(l,u);r=max(r,v);}

    }
    cout<<r-l+1<<endl;
    }
    return 0;
}