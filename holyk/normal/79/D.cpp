#include<bits/stdc++.h>
#define REP(i,a,b) for(register int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c,p=0;int w;
    while(isspace(c=getchar()));if(c=='-')p=1,c=getchar();w=c&15;
    while(isdigit(c=getchar()))w=w*10+(c&15);return p?-w:w;
}
template<typename T,typename U>inline bool smin(T&x,const U&y){return x>y?x=y,1:0;}
template<typename T,typename U>inline bool smax(T&x,const U&y){return x<y?x=y,1:0;}
const int N=1e4+5,inf=0x3f3f3f3f;
int n,k,m,a[N],c[105];
queue<int>q;
int d[22][N],b[22],cnt;
bool inq[N];
void bfs(int i){
    memset(d[i],0x3f,sizeof d[i]);
    d[i][b[i]]=0;q.push(b[i]);
    while(!q.empty()){
        int x=q.front();q.pop();inq[x]=0;
        REP(j,1,m){
            if(x-c[j]>=0&&smin(d[i][x-c[j]],d[i][x]+1)&&!inq[x-c[j]])q.push(x-c[j]),inq[x-c[j]]=1;
            if(x+c[j]<=n&&smin(d[i][x+c[j]],d[i][x]+1)&&!inq[x+c[j]])q.push(x+c[j]),inq[x+c[j]]=1;
        }
    }
}
int st,f[1<<20];
int dfs(int s){
    if(~f[s])return f[s];
    if(s==st)return 0;
    int&ans=f[s];ans=inf;
    int x=1;while(s>>x-1&1)++x; 
    REP(i,x+1,cnt)
        if(!(s>>i-1&1))smin(ans,dfs(s|(1<<x-1)|(1<<i-1))+d[x][b[i]]);
    return ans;
}
int main(){
    n=read(),k=read(),m=read();
    REP(i,1,k)a[read()]=1;
    REP(i,1,m)c[i]=read();
    REP(i,0,n)if(a[i]^a[i+1])b[++cnt]=i;
    st=(1<<cnt)-1;
    REP(i,1,cnt)bfs(i);
    memset(f,-1,sizeof f);
    int x=dfs(0);
    if(x==inf)puts("-1");else printf("%d\n",x);
    return 0;
}