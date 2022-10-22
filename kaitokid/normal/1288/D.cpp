#include <bits/stdc++.h>

using namespace std;
int n,m,u,k;
int a[300009][10];
int v[333];
bool go(int x)
{
    memset(v,0,sizeof v);
    for(int i=0;i<n;i++)
    {
        int q=0;
        for(int j=0;j<m;j++)if(a[i][j]>=x)q|=(1<<j);
        v[q]=i+1;
    }
    for(int i=1;i<300;i++)
        for(int j=i;j<300;j++)
    if(v[i]&&v[j]&&((i|j)==(1<<m)-1)){u=v[i];k=v[j];return true;}
    return false;
}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>a[i][j];
int l=0,r=1000000000;
 u=1,k=1;
while(r>l)
{
    int mid=(l+r+1)/2;
    if(go(mid))l=mid;
    else r=mid-1;

}
cout<<u<<" "<<k;
    return 0;
}