#include<bits/stdc++.h>
#define pbk emplace_back
#define cl(x) memset(x,0,sizeof x)
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
typedef long double ldb;
const int N=57;
int n,u,v,sz[N];
ldb f[N][N],g[N],tmp[N],fac[N];
vector<int>a[N];
ldb C(int n,int m){
    return fac[n]/fac[m]/fac[n-m];
}
void dfs(int x,int F){
    sz[x]=1,cl(f[x]),f[x][0]=1;
    for(int to:a[x])if(to!=F){
        dfs(to,x),sz[x]+=sz[to],cl(g),cl(tmp);
        FOR(i,0,sz[to])FOR(j,1,sz[to]){
            if(j<=i)g[i]+=0.5*f[to][j-1];
            else g[i]+=f[to][i];
        }
        FOR(i,0,sz[x])FOR(j,max(0,sz[to]+1+i-sz[x]),min(sz[to],i)){
            tmp[i]+=f[x][i-j]*g[j]*C(i,j)*C(sz[x]-1-i,sz[to]-j);
        }
        swap(tmp,f[x]);
    }
}
int main(){
    scanf("%d",&n),fac[0]=fac[1]=1;
    FOR(i,2,n){
        scanf("%d%d",&u,&v),a[u].pbk(v),a[v].pbk(u);
        fac[i]=fac[i-1]*i;
    }
    FOR(i,1,n)dfs(i,0),printf("%.9Lf\n",f[i][n-1]/fac[n-1]);
    return 0;
}