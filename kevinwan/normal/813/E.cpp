#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
struct nd{
    nd*l=0,*r=0;
    int seg=0;
};
#define mid ((l+r)>>1)
void upd(nd*m,nd*n,int l,int r,int a,int b){
    if(l==r)m->seg=n->seg+b;
    else{
        if(a<=mid){
            m->l=new nd();
            m->r=n->r;
            if(!n->l)n->l=new nd();
            upd(m->l,n->l,l,mid,a,b);
        }
        else{
            m->r=new nd();
            if(!n->r)n->r=new nd();
            upd(m->r,n->r,mid+1,r,a,b);
            m->l=n->l;
        }
        m->seg=(m->l?m->l->seg:0)+(m->r?m->r->seg:0);
    }
}
nd*t;
int qu(nd*n,int l,int r,int a,int b){
    if(l==a&&r==b)return n->seg;
    else{
        if(b<=mid)return n->l?qu(n->l,l,mid,a,b):0;
        else if(a>mid)return n->r?qu(n->r,mid+1,r,a,b):0;
        else return (n->l?qu(n->l,l,mid,a,mid):0)+(n->r?qu(n->r,mid+1,r,mid+1,b):0);
    }
}
nd*seg[mn];
int a[mn];
vector<int>ty[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i),ty[a[i]].push_back(i);
    seg[1]=new nd();
    for(int i=1;i<=100000;i++){
        for(int j=0;j<min(k,(int)ty[i].size());j++)
            t=new nd(),
            upd(t,seg[1],1,n,ty[i][j],1),
            seg[1]=t;
    }
    for(int i=2;i<=n;i++){
        seg[i]=new nd();
        int t=a[i-1];
        int idk=lower_bound(ty[t].begin(),ty[t].end(),i-1)-ty[t].begin();
        idk+=k;
        if(idk<ty[t].size())upd(seg[i],seg[i-1],1,n,ty[t][idk],1);
        else seg[i]=seg[i-1];
    }
    int lst=0;
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        a=(a+lst)%n+1;
        b=(b+lst)%n+1;
        if(a>b)swap(a,b);
        printf("%d\n",lst=qu(seg[a],1,n,a,b));
    }
}