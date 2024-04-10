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
const int inf=1061109567;
//const ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n;

int ci[333333];
char ch[333333];
struct edge{
    int v,next;
}e[16666666];int g[333333];int etot=0;
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int qu[333333],pre[333333];
int sz[333333];
void bfs(int rt){
    int p=0,q=0;
    qu[q++]=rt;
    pre[rt]=0;
    while(p!=q){
        int u=qu[p++];
        for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
            pre[e[i].v]=u;
            qu[q++]=e[i].v;
        }
    }
}

int ans[333333];

int chd[333333];
int chtot;

int off[333333]={0};
int cmpc(int a,int b){
    if(ch[a]==ch[b])return sz[a]>sz[b];
    return ch[a]<ch[b];
}


int go[333333][26]={0};
void merge(int u,int v){
    int ans=1;
    off[v]=1;
    for (int i=0;i<26;i++)if(go[v][i]){
        int tmp=go[u][i];
        if(tmp){
            merge(tmp,go[v][i]);
        }else{
            go[u][i]=go[v][i];
            ae(u,go[v][i]);
            //ans+=sz[go[v][i]];
        }
    }
    sz[u]=1;
    for (int i=0;i<26;i++)if(go[u][i])sz[u]+=sz[go[u][i]];
}
void work(int rt){
    chtot=0;
    for (int i=g[rt];~i;i=e[i].next)if(e[i].v!=pre[rt] && !off[e[i].v])chd[++chtot]=e[i].v;
    sort(chd+1,chd+1+chtot,cmpc);
    
    for (int i=1;i<=chtot;i++)if(i==1 || ch[chd[i]]!=ch[chd[i-1]]){
        for (int j=i+1;j<=chtot && ch[chd[j]]==ch[chd[i]];j++){
            merge(chd[i],chd[j]);
        }
    }

    sz[rt]=1;
    for (int i=1;i<=chtot;i++)if(!off[chd[i]]){
        sz[rt]+=sz[chd[i]];
        go[rt][ch[chd[i]]-'a']=chd[i];
    }
    //for (int i=g[rt];~i;i=e[i].next)if(e[i].v!=pre[rt])sz[rt]+=sz[e[i].v];
    ans[rt]=sz[rt];

}
int main()
{
    gn(n);
    memset(g,-1,sizeof(g));
    for (int i=1;i<=n;i++)gn(ci[i]);
    scanf("%s",ch+1);
    for (int i=1;i<n;i++){
        int x,y;
        gn(x);gn(y);
        ae(x,y);
        ae(y,x);
    }
    bfs(1);
    for (int i=n-1;i>=0;i--)work(qu[i]);
    int ma=0,cnt=0;

    for (int i=1;i<=n;i++)ans[i]+=ci[i];
    for (int i=1;i<=n;i++)if(ans[i]>ma){
        ma=ans[i];
        cnt=1;
    }else if(ans[i]==ma){
        cnt++;
    }
    //for (int u=1;u<=n;u++)printf("%d\n",ans[u]-ci[u]);
    printf("%d\n%d\n",ma,cnt);
    return 0;
}