#include <bits/stdc++.h>
using namespace std;
struct node{
    int lft,rit;
} ed[1001010];
vector<int> edge[1001010];
int rt,dia[1001010],dep[1001010],x,y,n,i,f[1001010],col[1001010],r1,r2,now,ans;
string color;
int find(int x)
{
    if (f[x]!=x) f[x]=find(f[x]);return f[x];
}
void sc(int x,int fa)
{
    int max1=0,max2=0;
    for (int i=0;i<edge[x].size();i++)
         {
            int y=edge[x][i];
            if (y==fa) continue;
            sc(y,x);
            dia[x]=max(dia[x],dia[y]);dep[x]=max(dep[x],dep[y]+1);
            if (dep[y]+1>max1)
                {
                max2=max1;max1=dep[y]+1;
                 }
                else if (dep[y]+1>max2) max2=dep[y]+1;
         }
    dia[x]=max(dia[x],max1+max2);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n;
    for (i=1;i<=n;i++)
        {
        cin>>color;
        if (color=="1") col[i]=1;
        else col[i]=2;
        }
    for (i=1;i<n;i++)
            {
            cin>>x>>y;
            ed[i].lft=x;ed[i].rit=y;
            }
    for (i=1;i<=n;i++) f[i]=i;
    for (i=1;i<n;i++)
        if (col[ed[i].lft]==col[ed[i].rit])
            { 
            r1=find(ed[i].lft);r2=find(ed[i].rit);
            f[r1]=r2;
            }
    now=0;
    for (i=1;i<=n;i++)
        if (find(ed[i].lft)!=find(ed[i].rit))
            {
                r1=find(ed[i].lft);r2=find(ed[i].rit);
                edge[r1].push_back(r2);edge[r2].push_back(r1);
                rt=r1;
            }
    sc(rt,0);
    ans=(dia[rt]+1)/2;
    cout<<ans<<endl;
    return 0;
}