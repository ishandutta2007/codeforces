#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int nx[100009],n,m,a[12][100009];
bool vis[100009];
ll ans,g;
void go(int x)
{
    g++;
    vis[x]=true;
    if(nx[x]!=-1)go(nx[x]);

}
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<m;i++)
{
    cin>>a[i][0];
    for(int j=1;j<n;j++)
    {
        cin>>a[i][j];
        if(nx[a[i][j-1]]==a[i][j])continue;
        if(nx[a[i][j-1]]==0)nx[a[i][j-1]]=a[i][j];
        else nx[a[i][j-1]]=-1;
    }
nx[a[i][n-1]]=-1;
}
for(int i=0;i<n;i++)
{
    int u=a[0][i];
     g=0;
    if(!vis[u])go(u);
    ans+=g*(g+1)/2;
}
cout<<ans;
   return 0;
}