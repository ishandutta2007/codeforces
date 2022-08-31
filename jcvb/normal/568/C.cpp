#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

char shu[50];
int sz;
int n,m;

int p1[555555],p2[555555];
char t1[555555],t2[555555];
int g[555];
struct edge{
    int v,next;
}e[555555];int etot=0;
void ae(int u,int v){
     e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int id[555]={0};
int dfn[555]={0},low[555]={0};
int stk[555],inst[555]={0},top=0;
int ind=0;
int sccnum=0;
void dfs(int u){
     dfn[u]=low[u]=++ind;
     inst[stk[++top]=u]=1;
     for (int i=g[u];~i;i=e[i].next){
         int v=e[i].v;
         if(!dfn[v]){
                     dfs(v);
                     low[u]=min(low[u],low[v]);
         }else if(inst[v]) low[u]=min(low[u],dfn[v]);
     }
     if(dfn[u]==low[u]){
                        ++sccnum;
                        while(stk[top]!=u){
                                           id[stk[top]]=sccnum;
                                           inst[stk[top--]]=0;
                        }
                        id[u]=sccnum;
                        inst[stk[top--]]=0;
     }
}

char str[555];
char ans[555];
int test(){
    ind=sccnum=top=0;
    for (int i=1;i<=2*n;i++)dfn[i]=0;
    for (int i=1;i<=2*n;i++)if(!dfn[i])dfs(i);
    for (int i=1;i<=n;i++)if(id[i]==id[i+n])return 0;
    return 1;
}

void dele(int u){
    g[u]=e[g[u]].next;
}


int doit(int i,int ls){
    if(i==n+1){
        for (int i=1;i<=n;i++)putchar(ans[i]);
        putchar('\n');
        return 1;
    }
    int olde=etot;  
    int a0,a1;
    ae(i+n,i);
    a0=test();
    etot=olde;dele(i+n);
    ae(i,i+n);
    a1=test();
    etot=olde;dele(i);
    if(!a0 && !a1)return 0;
    for (char c=(ls?'a':str[i]);c<='a'+sz-1;c++){
        int an;
        if(shu[c-'a']=='V')an=a0;
        else an=a1;
        if(an==1){
            ans[i]=c;
            if(shu[c-'a']=='V'){
                ae(i+n,i);
            }else{
                ae(i,i+n);
            }
            if(doit(i+1,ls|(ans[i]!=str[i])))return 1;
            if(shu[c-'a']=='V'){
                etot=olde;dele(i+n);
            }else{
                etot=olde;dele(i);
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%s",shu);
    sz=strlen(shu);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d",&p1[i]);
        while((t1[i]=getchar())<'A' || t1[i]>'Z');
        scanf("%d",&p2[i]);
        while((t2[i]=getchar())<'A' || t2[i]>'Z');
    }
    memset(g,-1,sizeof(g));
    int xv=0,xc=0;
    for (int i=0;i<sz;i++){
        if(shu[i]=='V')xv=1;
        if(shu[i]=='C')xc=1;
    }
    for (int i=1;i<=m;i++){
        int x=p1[i];
        if(t1[i]=='C')x+=n;
        int y=p2[i];
        if(t2[i]=='C')y+=n;
        ae(x,y);
        if(y>n)y-=n;else y+=n;
        if(x>n)x-=n;else x+=n;
        ae(y,x);
    }
    if(xv==0){
        for (int i=1;i<=n;i++)ae(i,i+n);
    }
    if(xc==0){
        for (int i=1;i<=n;i++)ae(i+n,i);
    }
    scanf("%s",str+1);
    if(!doit(1,0))printf("-1\n");
    return 0;
}