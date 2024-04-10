#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=55;
int k,w,h;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int pw[5];
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return res;
}
vector<int>p[6];
int pos[maxn];
void dfs1(int d,int v,int S){
    if(!d){
        v=add(v+1ll*p[d][0]*w%mod);pos[p[d][0]]=1;
        if(v==S){
            for(int i=1;i<=(1<<k);i++)printf("%d ",pos[i]);
            puts("");
            exit(0);
        }
        return ;
    }
    int len=(1<<(d-1));
    p[d-1].resize(len);
    for(int s=0;s<(1<<len);s++){
        int val=0;
        for(int i=0;i<len;i++){
            int u=p[d][2*i],v=p[d][2*i+1];
            if(s&(1<<i))p[d-1][i]=v,pos[u]=len+1,val=add(val+1ll*u*pw[d-1]%mod);
            else p[d-1][i]=u,pos[v]=len+1,val=add(val+1ll*v*pw[d-1]%mod);
        }
        dfs1(d-1,add(v+val),S);
    }
    return ;
}
unordered_map<int,bool>mp[(1<<16)+5];
void dfs2(int S,int d,int v){
    if(!d){
        v=add(v+1ll*w*p[d][0]%mod);
        mp[S][v]=1;
        return ;
    }
    int len=(1<<(d-1));
    p[d-1].resize(len);
    for(int s=0;s<(1<<len);s++){
        int val=0;
        for(int i=0;i<len;i++){
            int u=p[d][2*i],v=p[d][2*i+1];
            if(s&(1<<i))p[d-1][i]=v,val=add(val+1ll*u*pw[d-1]%mod);
            else p[d-1][i]=u,val=add(val+1ll*v*pw[d-1]%mod);
        }
        dfs2(S,d-1,add(v+val));
    }
    return ;
}
void dfs3(int d,int v){
    if(d==3){
        int s=0;
        for(int i=7;i>=0;i--)s<<=2,s|=(p[d][i]-4*i-1);
        if(mp[s][sub(h-v)]){dfs1(d,v,h);exit(0);}
        return ;
    }
    int len=(1<<(d-1));
    p[d-1].resize(len);
    for(int s=0;s<(1<<len);s++){
        int val=0;
        for(int i=0;i<len;i++){
            int u=p[d][2*i],v=p[d][2*i+1];
            if(s&(1<<i))p[d-1][i]=v,pos[u]=len+1,val=add(val+1ll*u*pw[d-1]%mod);
            else p[d-1][i]=u,pos[v]=len+1,val=add(val+1ll*v*pw[d-1]%mod);
        }
        dfs3(d-1,add(v+val));
    }
    return ;
}
int main(){
    k=read();w=read();h=read();
    for(int i=0;i<=4;i++)pw[i]=power(w,(1<<i)+1);
    if(k<=4){
        p[k].resize(1<<k);
        for(int i=0;i<p[k].size();i++)p[k][i]=i+1;
        dfs1(k,0,h);
        puts("-1");
        return 0;
    }
    for(int s=0;s<(1<<16);s++){
        p[3].resize(8);
        for(int i=0;i<8;i++){
            int op=(s>>(2*i))&3;
            p[3][i]=4*i+op+1;
        }
        dfs2(s,3,0);
    }
    p[5].resize(32);
    for(int i=0;i<p[5].size();i++)p[5][i]=i+1;
    dfs3(k,0);
    puts("-1");
    return 0;
}