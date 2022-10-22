#include<bits/stdc++.h>
using namespace std;
int n,a[100009];
vector<int>sg[200009];
vector<int>mrg(vector<int>&a,vector<int>&b)
{
    vector<int>res(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),res.begin());
    int u=min(32,(int)res.size());
    res.resize(u);
    return res;

}
void build(int x=0,int st=1,int en=n)
{
    sg[x].clear();
    if(st==en){sg[x].push_back(a[st]);return ;}
    int mid=(st+en)>>1;
    build(x+1,st,mid);
    build(x+((mid-st+1)<<1),mid+1,en);
    sg[x]=mrg(sg[x+1],sg[x+((mid-st+1)<<1)]);
}
vector<int>cal(int l,int r,int x=0,int st=1,int en=n)
{
    if(l>en||st>r)return {};
    if(l<=st&&r>=en)return sg[x];
    int mid=(st+en)>>1;
    vector<int>p1=cal(l,r,x+1,st,mid),p2=cal(l,r,x+((mid-st+1)<<1),mid+1,en);
    return mrg(p1,p2);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
           build();
           int q;
           scanf("%d",&q);
           while(q--)
           {
               int l,r;
                scanf("%d %d",&l,&r);
               vector<int>g=cal(l,r);
               int ans=INT_MAX;
               for(int i=0;i<g.size();i++)
                for(int j=i+1;j<g.size();j++)
                ans=min(ans,g[i]|g[j]);
               printf("%d\n",ans);
           }
    }
    return 0;
}