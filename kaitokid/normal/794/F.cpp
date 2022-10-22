#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
struct nod{

nod*l,*r;
ll val;
nod()
{
    l=r=NULL;
    val=0;
}
};
nod *sg[11];
void add(nod*&cur,int x,ll val,int st=1,int en=n)
{
    if(cur==NULL)cur=new nod();
    if(st>x||en<x)return ;
    if(st==en){cur->val+=val;return;}
    int md=st+(en-st)/2;
    add(cur->l,x,val,st,md);
    add(cur->r,x,val,md+1,en);
    cur->val=cur->l->val+cur->r->val;
}
void chn(nod*&cur1,nod*&cur2,int l,int r,int st=1,int en=n)
{
    if(st>r||l>en||cur1==NULL)return;
    int md=st+(en-st)/2;
    if(st>=l&&en<=r)
    {
        if(cur2==NULL){swap(cur1,cur2);return ;}
        chn(cur1->l,cur2->l,l,r,st,md);
        chn(cur1->r,cur2->r,l,r,md+1,en);
        cur2->val+=cur1->val;
        cur1=NULL;
        return;
    }
    if(cur2==NULL)cur2=new nod();
    chn(cur1->l,cur2->l,l,r,st,md);
    chn(cur1->r,cur2->r,l,r,md+1,en);
    ll d1=0,d2=0;
    if(cur1->l!=NULL)d1+=cur1->l->val;
    if(cur1->r!=NULL)d1+=cur1->r->val;
    if(cur2->l!=NULL)d2+=cur2->l->val;
    if(cur2->r!=NULL)d2+=cur2->r->val;
    cur1->val=d1;
    cur2->val=d2;


}
ll go(nod*&cur,int l,int r,int st=1,int en=n)
{
    if(cur==NULL||l>en||st>r)return 0;
    if(st>=l&&en<=r)return cur->val;
    int md=st+(en-st)/2;
    return go(cur->l,l,r,st,md)+go(cur->r,l,r,md+1,en);
}
int main()
{

for(int i=0;i<10;i++)sg[i]=new nod();
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        ll u=1;
        while(x>0)
        {

            add(sg[x%10],i,u);
            x/=10;
            u*=10;
        }

    }
    int t,l,r,x,y;
    while(q--)
    {
        cin>>t>>l>>r;
        if(t==1)
        {
            cin>>x>>y;
            if(x==y)continue;
            chn(sg[x],sg[y],l,r);
            continue;
        }
        ll ans=0;
      for(int i=1;i<10;i++)
            ans+=go(sg[i],l,r)*i;
      cout<<ans<<endl;
    }



    return 0;
}