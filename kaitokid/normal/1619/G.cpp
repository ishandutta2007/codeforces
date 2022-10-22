#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pr[200009],mn[200009];
int p(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=p(pr[x]);
}
void mrg(int x,int y)
{
    x=p(x);
    y=p(y);
    pr[x]=y;
    mn[y]=min(mn[y],mn[x]);
}

int x[200009],y[200009];
int id[200009];

bool b1(int u,int v)
{
    return make_pair(x[u],y[u])<make_pair(x[v],y[v]);
}
bool b2(int u,int v)
{
    return make_pair(y[u],x[u])<make_pair(y[v],x[v]);
}
vector<int>g;
bool ch(int x)
{
    int u=0;
    for(int i=0;i<g.size();i++)if(g[i]>x)u++;
    if(u<=x+1)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i]>>mn[i];
            pr[i]=i;
            id[i]=i;
        }
       sort(id,id+n,b1);
       for(int i=1;i<n;i++)
       {
           int u=id[i],v=id[i-1];
           if(x[u]!=x[v])continue;
           if(y[u]-y[v]>k)continue;
           mrg(u,v);
       }

       sort(id,id+n,b2);
       for(int i=1;i<n;i++)
       {
           int u=id[i],v=id[i-1];
           if(y[u]!=y[v])continue;
           if(x[u]-x[v]>k)continue;
           mrg(u,v);
       }
       g.clear();
       for(int i=0;i<n;i++)if(p(i)==i)g.push_back(mn[i]);
       int l=0,r=1000000000;
       while(r>l)
       {
           int mid=(l+r)/2;
           if(ch(mid))r=mid;
           else l=mid+1;
       }
       cout<<l<<endl;
    }

    return 0;
}