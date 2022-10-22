#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=5e5+5,maxq=5e5+5,maxk=55;
int n,m,K,q;
int ed[maxm][2];
int que[maxq][2];
int lst[maxm];
int co[maxm];
int f[maxk][2*maxn],rk[maxk][2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vector<int>upd[maxq<<2];
void insert(int k,int l,int r,int x,int y,int id){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){
        upd[k].push_back(id);
//        cout<<"@"<<k<<" "<<l<<" "<<r<<" "<<id<<endl;
        return ;
    }
    int mid=l+((r-l)>>1);
    insert(k<<1,l,mid,x,y,id);
    insert(k<<1|1,mid+1,r,x,y,id);
    return ;
}
int find(int c,int x){
    if(f[c][x]==x)return x;
    return find(c,f[c][x]);
}
int tp=0;
int st[2*maxq+2*maxm][3];
int link(int c,int x,int y){
    int u=find(c,x),v=find(c,y);
    if(u==v)return 0;
    if(rk[u]>rk[v])swap(u,v);
    f[c][u]=v;tp++;st[tp][0]=c;st[tp][1]=u;
    if(rk[c][v]==rk[c][u])rk[c][v]++,st[tp][2]=v;
    return 1;
}
void recall(){
    int c=st[tp][0],u=st[tp][1],v=st[tp][2];
    f[c][u]=u;
    if(v)rk[c][v]--;
    tp--;
}
void dfs(int k,int l,int r){
    int num=0;
    for(int i=0;i<upd[k].size();i++){
        int id=upd[k][i],u=ed[id][0],v=ed[id][1];
        if(!co[id])continue;
        num+=link(co[id],u,v+n);num+=link(co[id],v,u+n);
//        cout<<"#"<<co[id]<<" "<<u<<" "<<v+n<<endl;
//        cout<<"#"<<co[id]<<" "<<v<<" "<<u+n<<endl;
    }
//    cout<<"*"<<k<<" "<<l<<" "<<r<<endl;
//    for(int c=1;c<=K;c++)for(int i=1;i<=2*n;i++)cout<<c<<" "<<i<<" "<<find(c,i)<<endl;
    if(l==r){
        if(l==q){for(int i=1;i<=num;i++)recall();return ;}
        int c=que[l+1][1],id=que[l+1][0],u=ed[id][0],v=ed[id][1];
        bool tag1=0,tag2=0;
        tag1=link(c,u,v+n);tag2=link(c,v,u+n);
        if(find(c,u)!=find(c,u+n)){co[id]=c;puts("YES");}
        else puts("NO");
        if(tag1)recall();if(tag2)recall();
        for(int i=1;i<=num;i++)recall();
        return ;
    }
    int mid=l+((r-l)>>1);
    dfs(k<<1,l,mid);
//    cout<<"qaq\n";
    dfs(k<<1|1,mid+1,r);
    for(int i=1;i<=num;i++)recall();
    return ;
}
int main(){
    n=read();m=read();K=read();q=read();
    for(int i=1;i<=m;i++){
        int u,v;
        u=read();v=read();
        ed[i][0]=u;ed[i][1]=v;
    }
    for(int i=1;i<=q;i++){
        int e,c;
        e=read();c=read();
        que[i][0]=e;que[i][1]=c;
        if(lst[e])insert(1,1,q,lst[e],i-1,e);
        lst[e]=i;
    }
    for(int i=1;i<=m;i++)if(lst[i])insert(1,1,q,lst[i],q,i);
    for(int c=1;c<=K;c++)for(int i=1;i<=2*n;i++)f[c][i]=i;
    co[que[1][0]]=que[1][1];puts("YES");
    dfs(1,1,q);
    return 0;
}