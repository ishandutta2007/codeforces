#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=201000;
int n,m;
int cnt[maxn],w[maxn];
int a[maxn],b[maxn];
bool vis[maxn],cls[maxn];
queue <int> q[maxn],q2;
int ans[maxn],tnt;
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i)
        w[i]=read();
    for(int i=1;i<=m;++i){
        a[i]=read();b[i]=read();
        q[a[i]].push(i);
        q[b[i]].push(i);
        ++cnt[a[i]];
        ++cnt[b[i]];
    }
    for(int i=1;i<=n;++i)
        if(cnt[i]<=w[i]){
            q2.push(i);
            cls[i]=true;
        }
    while(q2.size()){
        int p=q2.front();
        q2.pop();
        while(q[p].size()){
            int t=q[p].front();
            q[p].pop();
            if(vis[t])continue;
            vis[t]=true;
            --cnt[a[t]];--cnt[b[t]];
            if(!cls[a[t]]&&cnt[a[t]]<=w[a[t]])
                q2.push(a[t]),cls[a[t]]=true;
            if(!cls[b[t]]&&cnt[b[t]]<=w[b[t]])
                q2.push(b[t]),cls[b[t]]=true;
            ans[++tnt]=t;
        }
    }
    if(tnt<m)puts("DEAD");
    else{
        puts("ALIVE");
        while(tnt)printf("%d ",ans[tnt--]);
    }
    return 0;
}