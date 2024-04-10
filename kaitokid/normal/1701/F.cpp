#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
struct nod
{
    ll sum,num,lz;
    nod()
    {
        sum=num=lz=0;
    }
};
nod sg[4*N];

nod mrg(nod x,nod y)
{
    nod res;
    res.sum=x.sum+y.sum;
    res.num=x.num+y.num;
    return res;
}
void push(int x,int l,int r)
{
sg[x].sum+=sg[x].num*sg[x].lz;
if(l!=r)
{
    sg[2*x+1].lz+=sg[x].lz;
    sg[2*x+2].lz+=sg[x].lz;

}
sg[x].lz=0;
}
nod cal(int l,int r,int rt=1,int st=0,int en=200001)
{
    push(rt,st,en);
    if(l<=st && en<=r)return sg[rt];
    if(st>r || l>en)return nod();
    int mid=(st+en)/2;
    return mrg(cal(l,r,2*rt+1,st,mid),cal(l,r,2*rt+2,mid+1,en));

}
void add(int l,int r,int x,int rt=1,int st=0,int en=200001)
{
    push(rt,st,en);
    if(l<=st && en<=r){sg[rt].lz+=x;push(rt,st,en);return;}
    if(st>r || l>en)return ;
    int mid=(st+en)/2;
     add(l,r,x,2*rt+1,st,mid);
     add(l,r,x,2*rt+2,mid+1,en);

     sg[rt]=mrg(sg[2*rt+1],sg[2*rt+2]);

}
void ins(int l,int x,int rt=1,int st=0,int en=200001)
{
    push(rt,st,en);
    if(st>l || l>en)return ;
    if(st==en){sg[rt]=nod();sg[rt].sum=x;sg[rt].num=1;return;}
    int mid=(st+en)/2;
     ins(l,x,2*rt+1,st,mid);
     ins(l,x,2*rt+2,mid+1,en);

     sg[rt]=mrg(sg[2*rt+1],sg[2*rt+2]);

}

void rem(int l,int rt=1,int st=0,int en=200001)
{
    push(rt,st,en);
    if(st>l || l>en)return ;
    if(st==en){sg[rt]=nod();sg[rt].sum=sg[rt].num=0;return;}
    int mid=(st+en)/2;
     rem(l,2*rt+1,st,mid);
     rem(l,2*rt+2,mid+1,en);

     sg[rt]=mrg(sg[2*rt+1],sg[2*rt+2]);

}
int q,d;
bool bl[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>q>>d;
    ll ans=0;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        if(!bl[x])
        {
            bl[x]=true;
            nod u=cal(x,min(x+d,200001));
            ans+=u.num*(u.num-1)/2;
            ins(x,u.num);
            u=cal(max(x-d,0),x-1);
            ans+=u.sum;
            add(max(x-d,0),x-1,1);
            cout<<ans<<endl;
            continue;
        }

            bl[x]=false;
            nod u=cal(x+1,min(x+d,200001));
            ans-=u.num*(u.num-1)/2;
            rem(x);
            u=cal(max(x-d,0),x-1);
            ans-=u.sum-u.num;
            add(max(x-d,0),x-1,-1);
            cout<<ans<<endl;
            continue;
    }


    return 0;
}