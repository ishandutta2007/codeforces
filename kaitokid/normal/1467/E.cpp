#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct nod{
nod*l,*r;
int v;
nod()
{
    l=r=NULL;
    v=0;
}
};
nod*sg[200009];
vector<int>ed[200009];
int x[400009],y[400009],edg,n,a[200009];
int pr[200009],st[200009],en[200009];
bool dp[400009];
int mp[200009];
vector<int>val;
int rr;
void go(int x,int p)
{
    st[x]=val.size();
    val.push_back(a[x]);
    for(int i=0;i<ed[x].size();i++)
    {if(y[ed[x][i]]==p)continue;
    int u=y[ed[x][i]];
    pr[u]=x;
    go(u,x);
    }
    en[x]=val.size()-1;


}
void add(nod*&root,int st,int en,int x)
{
    if(root==NULL)root=new nod();
    if(x<st||x>en)return;
    if(st==en){root->v=1;return;}
    int md=st+(en-st)/2;
    add(root->l,st,md,x);
    add(root->r,md+1,en,x);
    root->v=root->l->v+root->r->v;

}
int fn(nod*&root,int st,int en,int l,int r)
{
    if(en<l||st>r||root==NULL)return 0;
    if(st>=l&&en<=r)return root->v;
    int md=st+(en-st)/2;
    return fn(root->l,st,md,l,r)+fn(root->r,md+1,en,l,r);

}
bool ch(int x,int y)
{
 if(pr[y]==x)
 {
     return (fn(sg[a[x]],0,val.size()-1,st[y],en[y])==0);
 }

     return (fn(sg[a[x]],0,val.size()-1,st[x],en[x])==mp[a[x]]);
}
void fuck(int u)
{
    if(dp[u])return;
    dp[u]=1;
    for(int i=0;i<ed[x[u]].size();i++)
    {int r=(ed[x[u]][i]);
    if(r==u)continue;
    r^=1;
    fuck(r);
        }

}
int main()
{
    scanf("%d",&n);
    vector<int>hs;
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);hs.push_back(a[i]);}
    sort(hs.begin(),hs.end());
    for(int i=1;i<=n;i++){a[i]=lower_bound(hs.begin(),hs.end(),a[i])-hs.begin();    mp[a[i]]++;}
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        x[edg]=y[edg+1]=a;
        x[edg+1]=y[edg]=b;
        ed[a].push_back(edg);
        ed[b].push_back(edg+1);
        edg+=2;

    }
    go(1,0);

    for(int i=1;i<=n;i++)add(sg[a[i]],0,val.size()-1,st[i]);

    for(int i=0;i<edg;i++)
        if((dp[i]==0)&&!ch(x[i],y[i]))
        fuck(i);

 int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans++;
        for(int j=0;j<ed[i].size();j++)if(dp[ed[i][j]]==1){ans--;break;}
    }
printf("%d",ans);

      return 0;
}