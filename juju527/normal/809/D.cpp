#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{int rd,ls,rs,v,laz;}t[maxn];
int tot,rt;
int newnode(int v){
    int k=++tot;
    t[k]=(node){rand(),0,0,v,0};
    return k;
}
void add_laz(int k,int v){
    t[k].v+=v;t[k].laz+=v;
    return ;
}
void pushdown(int k){
    if(!t[k].laz)return ;
    add_laz(t[k].ls,t[k].laz),add_laz(t[k].rs,t[k].laz);
    t[k].laz=0;
    return ;
}
void split(int k,int &a,int &b,int val){
    if(!k){a=b=0;return ;}
    pushdown(k);
    if(t[k].v<=val)a=k,split(t[k].rs,t[a].rs,b,val);
    else b=k,split(t[k].ls,a,t[b].ls,val);
    return ;
}
void merge(int &k,int a,int b){
    if(!a||!b){k=a+b;return ;}
    pushdown(a),pushdown(b);
    if(t[a].rd<t[b].rd)k=a,merge(t[k].rs,t[a].rs,b);
    else k=b,merge(t[k].ls,a,t[b].ls);
    return ;
}
void ins(int v){
    int a=0,b=0,c=newnode(v);
    split(rt,a,b,v);
    merge(a,a,c),merge(rt,a,b);
    return ;
}
void modify(int l,int r){
    if(l>r)return ;
    int a=0,b=0,c=0;
    split(rt,a,b,l-1),split(b,b,c,r);
    add_laz(b,1);
    merge(b,b,c),merge(rt,a,b);
    return ;
}
void del(int v){
    int a=0,b=0,c=0,w;
    split(rt,a,b,v-1);
    c=b;while(t[c].ls)c=t[c].ls;w=t[c].v;c=0;
    split(b,b,c,w);
    merge(rt,a,c);
    return ;
}
int res=0;
void dfs(int x){
    if(!x)return ;
    dfs(t[x].ls);
    res++;
    dfs(t[x].rs);
    return ;
}
int main(){
    srand(time(0));
    int n;
    n=read();
    ins(0);
    for(int i=1;i<=n;i++){
        int l,r;
        l=read();r=read();
        del(r);modify(l,r-1);ins(l);
    }
    res=0;dfs(rt);
    printf("%d\n",res-1);
    return 0;
}