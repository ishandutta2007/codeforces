#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int pr[300009],gg[300009];
deque<int>cm[300008];
int x[300009],y[300009];
int vis[300009];
vector<int>bf[300009];
void mrg(int a,int b)
{
    if(a==b)return;
    if(cm[a].size()<cm[b].size())
    {
        while(cm[a].size())
        {
            int u=cm[a].back();
            cm[b].push_front(u);
            pr[u]=b;
            cm[a].pop_back();
        }
        return;
    }
    while(cm[b].size())
        {
            int u=cm[b].front();
            cm[a].push_back(u);
            pr[u]=a;
            cm[b].pop_front();
        }
}
vector<int>ans;
int res,id,pos[300009];
void go(int x)
{
   // cout<<x<<endl;
    if(vis[x]==2||res==-1)return;
    if(vis[x]==1){res=-1;return;}
    vis[x]=1;
    for(int i=0;i<bf[x].size();i++)
        go(bf[x][i]);
    vis[x]=2;
    while(cm[x].size())
    {

        ans.push_back(cm[x].front());
        pos[cm[x].front()]=id++;
        cm[x].pop_front();
    }

}
int main()
{
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        pr[i]=i;
        cm[i].push_back(i);
        cin>>gg[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>x[i]>>y[i];
        mrg(pr[x[i]],pr[y[i]]);

    }

   for(int i=1;i<=n;i++)
   {
       //cout<<cm[i].size()<<endl;
       if(pr[i]!=pr[gg[i]])bf[pr[i]].push_back(pr[gg[i]]);
   }
 for(int i=1;i<=n;i++)
    if(vis[pr[i]]==0)go(pr[i]);

    if(res==-1)
    {
        cout<<0;return 0;
    }
    for(int i=1;i<=n;i++)
    if(pos[i]<pos[gg[i]]){cout<<0;return 0;}
    for(int i=0;i<k;i++)
        if(pos[y[i]]!=pos[x[i]]+1){cout<<0;return 0;}
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}