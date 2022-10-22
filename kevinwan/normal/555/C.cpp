#include <bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
struct nd{
    nd*l,*r;
    int seg=0;
};
nd* seg[2];
void update(nd*&n,int l,int r,int a,int b,int c){
    if(b<a)return;
    if(a==l&&b==r)n->seg=max(n->seg,c);
    else{
        if(!n->l)n->l=new nd();
        if(!n->r)n->r=new nd();
        if(n->seg){
            n->l->seg=max(n->l->seg,n->seg);
            n->r->seg=max(n->r->seg,n->seg);
            n->seg=0;
        }
        if(b<=mid)update(n->l,l,mid,a,b,c);
        else if(a>mid)update(n->r,mid+1,r,a,b,c);
        else update(n->l,l,mid,a,mid,c),update(n->r,mid+1,r,mid+1,b,c);
    }
}
int query(nd*&n,int l,int r,int a){
    if(l==r)return n->seg;
    else{
        if(!n->l)n->l=new nd();
        if(!n->r)n->r=new nd();
        if(n->seg){
            n->l->seg=max(n->l->seg,n->seg);
            n->r->seg=max(n->r->seg,n->seg);
            n->seg=0;
        }
        if(a<=mid)return query(n->l,l,mid,a);
        else return query(n->r,mid+1,r,a);
    }
}
int main()
{
    seg[0]=new nd();
    seg[1]=new nd();
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--){
        int a,b;
        char c;
        scanf("%d%d %c",&a,&b,&c);
        c=(c=='U');
        if(c)swap(a,b);
        int ans=a-query(seg[c],1,n,a);
        update(seg[c],1,n,a,a,a);
        update(seg[!c],1,n,b,b+ans-1,b);
        printf("%d\n",ans);
    }
}