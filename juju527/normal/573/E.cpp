#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{
    int rd,ls,rs,siz;
    ll v,laz,sum;
}t[maxn];
int rt,tot;
int newnode(ll v){
    int k=++tot;
    t[k]=(node){rand(),0,0,1,v,0,v};
    return k;
}
void pushup(int k){
    if(!k)return ;
    int ls=t[k].ls,rs=t[k].rs;
    t[k].siz=t[ls].siz+t[rs].siz+1;
    t[k].sum=t[ls].sum+t[rs].sum+t[k].v;
    return ;
}
void add_laz(int k,ll v){
    if(!k)return ;
    t[k].laz+=v;t[k].v+=v;t[k].sum+=v*t[k].siz;
    return ;
}
void pushdown(int k){
    if(t[k].laz==0)return ;
    add_laz(t[k].ls,t[k].laz),add_laz(t[k].rs,t[k].laz);
    t[k].laz=0;
    return ;
}
void split(int k,int &a,int &b,int s){
    if(!k){a=b=0;return ;}
    pushdown(k);
    if(t[t[k].ls].siz+1<=s)a=k,split(t[k].rs,t[a].rs,b,s-t[t[k].ls].siz-1);
    else b=k,split(t[k].ls,a,t[b].ls,s);
    pushup(k);
    return ;
}
void merge(int &k,int a,int b){
    if(!a||!b){k=a+b;return ;}
    pushdown(a);pushdown(b);
    if(t[a].rd<t[b].rd)k=a,merge(t[k].rs,t[a].rs,b);
    else k=b,merge(t[k].ls,a,t[b].ls);
    pushup(k);
    return ;
}
ll F=0,res=0;
/*void out(int x){
    if(!x)return ;
    pushdown(x);
    out(t[x].ls);
    F+=t[x].v;
    cout<<F<<" ";
    out(t[x].rs);
    return ;
}*/
void dfs(int x){
    if(!x)return ;
    pushdown(x);
    dfs(t[x].ls);
    F+=t[x].v;
    res=max(res,F);
    dfs(t[x].rs);
    return ;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    rt=newnode(a[1]);
    for(int i=2;i<=n;i++){
        int x=rt,pos=i,sum=0,id=0;
        while(x){
            pushdown(x);
            int ls=t[x].ls;
            ll v1=sum+t[ls].sum+1ll*(t[ls].siz+id+1)*a[i];
            ll v2=sum+t[ls].sum+t[x].v;
            if(v1>=v2){
                pos=min(pos,id+t[ls].siz+1);
                x=t[x].ls;
            }
            else sum+=t[ls].sum+t[x].v,id+=t[ls].siz+1,x=t[x].rs;
        }
        int A=0,B=0,C=0;
        if(pos==1){
            merge(rt,newnode(0),rt);
            add_laz(rt,a[i]);
        }
        else{
            split(rt,A,B,pos-2),split(B,B,C,1);
            merge(A,A,newnode(t[B].v));
            t[B].v=1ll*pos*a[i],add_laz(C,a[i]);
            merge(B,B,C),merge(rt,A,B);
        }
//        cout<<"#"<<pos<<endl;
//        F=0,out(rt);printf("\n");
    }
    F=0,dfs(rt);
    printf("%lld\n",res);
    return 0;
}