#include <bits/stdc++.h>
#define pb push_back

using namespace std;
long n,i,m,k,h[1000005]={0},u[1000005],v[1000005],cur=1,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(i=0;i<m;++i)
        {cin>>x;
        h[x]=1;}
    for(i=0;i<k;++i)
        cin>>u[i]>>v[i];
    if(h[1]!=1)
    for(i=0;i<k;++i)
    {
        if(h[u[i]]==1 && v[i]==cur) {cur=u[i];break;}
        if(h[v[i]]==1 && u[i]==cur) {cur=v[i];break;}
        if(v[i]==cur) cur=u[i];
        else if(u[i]==cur) cur=v[i];
    }
    cout<<cur;
    return 0;
}