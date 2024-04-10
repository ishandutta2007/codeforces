#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nod{
nod*l,*r;
int val;
};
nod*sg[100009];
int cal(nod*rt,int l,int r,int st=0,int en=100000)
{
    if(r<l || en < l || st>r) return 0;
    if(st>=l && en<=r)return rt->val;;
    if(rt->l==NULL)rt->l=new nod();
    if(rt->r==NULL)rt->r=new nod();
    int mid=(st+en)/2;
    return max(cal(rt->l,l,r,st,mid),cal(rt->r,l,r,mid+1,en));
}
void upd(nod*rt,int x,int val,int st=0,int en=100000)
{
    if(x<st || x>en)return ;
    if(st==en)
    {
        rt->val=max(rt->val,val);
        return;
    }
    if(rt->l==NULL)rt->l=new nod();
    if(rt->r==NULL)rt->r=new nod();
    int mid=(st+en)/2;
    upd(rt->l,x,val,st,mid);
    upd(rt->r,x,val,mid+1,en);
    rt->val=max(rt->l->val,rt->r->val);
}
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)sg[i]=new nod();
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        int  res=1+cal(sg[x],0,w-1);
        ans=max(ans,res);
        upd(sg[y],w,res);
    }
    cout<<ans;
    return 0;
}