#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N],c1,c2;
int n,q,a,b;
struct node{
    int d,a,b,ab,ba,abc;
    node operator+(int x){
        return (node){d,a+x,b-(x<<1),ab-x,ba-x,abc};
    }
}tre[N<<2],lp,rp;
node operator+(const node &a,node b){
    b=b+a.d;
    static node c;
    c.d=a.d+b.d;
    c.a=max(a.a,b.a);
    c.b=max(a.b,b.b);
    c.ab=max(max(a.ab,b.ab),a.a+b.b);
    c.ba=max(max(a.ba,b.ba),a.b+b.a);
    c.abc=max(max(a.abc,b.abc),max(a.ab+b.a,a.a+b.ba));
    return c;
}
#define mid (l+r>>1)
#define ls o<<1,l,mid
#define rs o<<1|1,mid+1,r
void add(int o,int l,int r,int v,char ch){
    if(l==r){
        if(ch=='(')tre[o]=lp;
        else       tre[o]=rp;
        return;
    }
    if(v<=mid)add(ls,v,ch);else add(rs,v,ch);
    tre[o]=tre[o<<1]+tre[o<<1|1];
}
void dbg(int o,int l,int r){
    printf("%d [%d,%d]: %d %d %d %d %d %d\n",o,l,r,tre[o].d,tre[o].a,tre[o].b,tre[o].ab,tre[o].ba,tre[o].abc);
    if(l==r)return;
    dbg(ls);dbg(rs);
}
int main(){
    scanf("%d%d%s",&n,&q,s+1);n=(n-1)<<1;
    lp=(node){ 1,1,0,0,1,1};
    rp=(node){-1,0,2,2,1,1};
    for(int i=1;i<=n;i++)add(1,1,n,i,s[i]);
    printf("%d\n",tre[1].abc);//dbg(1,1,n);
    while(q--){
        scanf("%d%d",&a,&b);
        c1=s[b];c2=s[a];
        add(1,1,n,a,c1);
        add(1,1,n,b,c2);
        s[a]=c1;s[b]=c2;
        printf("%d\n",tre[1].abc);//dbg(1,1,n);
    }
    return 0;
}