#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=600,inf=2e9;
 
int n,m,d[N][N],g[N][N],dist[N][N],mark[N];
 
void do_it(int x){
   f(i,0,n)
      f(j,0,n)
         minm(d[x][i],g[x][j]+(i-j+n)%n);
}
void bfs(int x){
    dist[x][x]=0;
    fill(mark,mark+N,0);
    f(i,0,n){
        int u,e=inf;
        f(j,0,n)
            if(!mark[j] && dist[x][j]<e)
                u=j,e=dist[x][j];
        mark[u]=1;
        e=dist[x][u]%n;
        f(j,0,n)
            minm(dist[x][(j+e)%n],dist[x][u]+d[u][j]);
    }
}
 
int main(){
    f(i,0,N)
        f(j,0,N)
            g[i][j]=inf,d[i][j]=inf,dist[i][j]=inf;
  cin>>n>>m;
  f(i,0,m){
      int u,v,c;
      cin>>u>>v>>c;
      g[u][v]=c;
  }
  f(i,0,n)
      do_it(i);
  f(i,0,n)
      bfs(i);
  f(i,0,n){
      f(j,0,n)
          cout<<dist[i][j]<<" ";
        cout<<endl;
    }
}