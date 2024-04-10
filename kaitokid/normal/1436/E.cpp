#include <bits/stdc++.h>

using namespace std;

int lst[100009],n,a[100009];

struct nod;
extern nod*empty;
struct nod{
int mn;
nod *l,*r;
nod(){
mn=0;
l=this;
r=this;
}
nod(int x,nod*lf=empty,nod*ri=empty)
{
    mn=x;
    l=lf;
    r=ri;
}
};
nod*empty=new nod();
nod*sg[100009];
nod*ins (nod*root,int x,int y,int st=1,int en=n+2)
{
    if(x<st||x>en)return root;

    if(st==en)
   return new nod(y);

    int md=st+(en-st)/2;
      nod*u=ins(root->l,x,y,st,md);
    nod*v=ins(root->r,x,y,md+1,en);
    return new nod(min(u->mn,v->mn),u,v);


}
int go(nod*root,int x,int st=1,int en=n+2)
{
    int mid=st+(en-st)/2;
    if(st==en)return st;
    if(root->l->mn<x)go(root->l,x,st,mid);
    else go(root->r,x,mid+1,en);
}
int cal(int x,int y)
{
    if(x>y)return 0;
    return go(sg[y],x);
}
vector<int>g[100009];
int main()
{ios::sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n+2;i++)g[i].push_back(0);
sg[0]=empty;
for(int i=1;i<=n;i++)
{
    int x;
    cin>>x;
    g[x].push_back(i);
    lst[x]=i;
    sg[i]=ins(sg[i-1],x,lst[x]);

}

for(int i=1;i<=n+2;i++)g[i].push_back(n+1);

for(int i=1;i<=n+2;i++)
{
    bool bl=true;
    for(int j=1;j<g[i].size();j++)
    if(cal(g[i][j-1]+1,g[i][j]-1)==i){bl=false;break;}
    if(bl){cout<<i;return 0;}
}
    return 0;
}