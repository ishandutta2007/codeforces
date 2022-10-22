#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[100009];
int g[100009][20],pr[100009],n;
void mrg(int x,int y,int z)
{
    if(v[x].size()>v[y].size())swap(x,y);
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if((u>1)&&(pr[u-1]==y))g[u-1][0]=z;
        if((u<n)&&(pr[u+1]==y))g[u][0]=z;
    }
    for(int i=0;i<v[x].size();i++){pr[v[x][i]]=y;v[y].push_back(v[x][i]);}
    v[x].clear();

}
int lg[100009];
int cal(int x,int y)
{
    if(y<x)return 0;
    int u=lg[y-x+1];
   // cout<<x<<" "<<y<<" "<<u<<endl;
    return max(g[x][u],g[y-(1<<u)+1][u]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;i<=100000;i++)
        lg[i]=lg[i-1]+((i&(i-1))==0);

    int t;
    cin>>t;
    while(t--)
    {
        int m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
        {
            pr[i]=i;
            v[i].clear();
            v[i].push_back(i);
        }
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            if(pr[x]==pr[y])continue;

            mrg(pr[x],pr[y],i);
        }
      // for(int i=1;i<n;i++)cout<<g[i][0]<<" ";
       //cout<<endl;
       for(int i=1;(1<<i)<=n;i++)
            for(int j=1;j+(1<<i)<=n+1;j++)
            g[j][i]=max(g[j][i-1],g[j+(1<<(i-1))][i-1]);

       while(q--)
       {
           int x,y;
           cin>>x>>y;
           cout<<cal(x,y-1)<<" ";
       }
       cout<<endl;
     }
    return 0;
}