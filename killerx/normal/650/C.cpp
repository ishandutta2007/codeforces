#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
const int N=1<<20;
int n,m;
int a[N];
int fa[N];
int id[N],c;
int e[N<<1][2],ec;
int Fa(int x){return fa[x]==x?x:fa[x]=Fa(fa[x]);}
int head[N],nxt[N<<1],to[N<<1],tot;
int in[N];
void add(int u,int v){
    nxt[tot]=head[u];head[u]=tot;
    to[tot]=v;++tot;in[v]++;
}
int que[N],l,r;
int ans[N];
void bfs(){
    l=r=0;
    for(int i=0;i<n*m;++i)if(Fa(i)==i){
        if(!in[i])que[r++]=i,ans[i]=1;
    }
    while(l<r){
        int u=que[l++];
        for(int e=head[u];~e;e=nxt[e]){
            int v=to[e];
            in[v]--;
            ans[v]=max(ans[v],ans[u]+1);
            if(!in[v]){
                que[r++]=v;
            }
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i=0;i<n*m;++i)a[i]=read();
    for(int i=0;i<n*m;++i)fa[i]=i;
    for(int i=0;i<n;++i){
        c=0;
        for(int j=0;j<m;++j)id[c++]=i*m+j;
        sort(id,id+c,[&](int x,int y){return a[x]<a[y];});
        for(int j=1;j<c;++j){
            if(a[id[j]]==a[id[j-1]])fa[Fa(id[j])]=Fa(id[j-1]);
            else e[ec][0]=id[j-1],e[ec][1]=id[j],++ec;
        }
    }
    for(int i=0;i<m;++i){
        c=0;
        for(int j=0;j<n;++j)id[c++]=j*m+i;
        sort(id,id+c,[&](int x,int y){return a[x]<a[y];});
        for(int j=1;j<c;++j){
            if(a[id[j]]==a[id[j-1]])fa[Fa(id[j])]=Fa(id[j-1]);
            else e[ec][0]=id[j-1],e[ec][1]=id[j],++ec;
        }
    }
    memset(head,-1,sizeof head);
    for(int i=0;i<ec;++i){
        add(Fa(e[i][0]),Fa(e[i][1]));
    }
    bfs();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%d",ans[Fa(i*m+j)]);
            putchar(j+1==m?'\n':' ');
        }
    }
	return 0;
}