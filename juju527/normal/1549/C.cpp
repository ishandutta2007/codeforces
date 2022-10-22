#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
set<int>s[maxn];
bool vis[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int u,v;
        u=read();v=read();
        s[u].insert(-v);s[v].insert(-u);
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(!s[i].size())vis[i]=1,num++;
        else if(-*s[i].begin()<i)vis[i]=1,num++;
    }
    int q;
    q=read();
    while(q--){
        int opt,u,v;
        opt=read();
        if(opt!=3)u=read(),v=read();
        if(opt==1){
            s[u].insert(-v);s[v].insert(-u);
            if(vis[u]&&-*s[u].begin()>u)vis[u]=0,num--;
            if(vis[v]&&-*s[v].begin()>v)vis[v]=0,num--;
        }
        else if(opt==2){
            s[u].erase(-v);s[v].erase(-u);
            if(!vis[u]&&-*s[u].begin()<u)vis[u]=1,num++;
            if(!vis[v]&&-*s[v].begin()<v)vis[v]=1,num++;
        }
        else printf("%d\n",num);
    }
    return 0;
}