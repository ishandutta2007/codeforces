#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
vector < long long > a[100005],c[100005];
int main()
{
    long long n,m,j,i,x,k,l,r,mn;
    cin>>n>>m;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {   cin>>x;
            a[i].pb(x);if(i==0) c[0].pb(0);}
    }
    c[0].pb(0);
    for(i=1;i<n;++i)
    {
        mn=1000000007;
        for(j=0;j<m;++j)
        {
            if(a[i][j]>=a[i-1][j]) c[i].pb(c[i-1][j]);
            else c[i].pb(i);
            mn=min(mn,c[i][j]);
        }
        c[i].pb(mn);
    }
    cin>>k;
    while(k--)
    {
        cin>>l>>r;
        if(c[r-1][m]<=l-1)
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}