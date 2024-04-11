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

const int N=1e6+99;

int n,m,t,dist[N],ans[N];
vector<pair<int,int> > g[N];

void bfs(){
    fill(dist,dist+N,N);
    queue<int> q;
    q.push(n);
    dist[n]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        f(i,0,g[u].size()){
            if(ans[g[u][i].F]==-1){
                ans[g[u][i].F]=g[u][i].S^1;
            }
            else
                if(dist[u]+1<dist[g[u][i].F] && ans[g[u][i].F]==g[u][i].S){
                    dist[g[u][i].F]=dist[u]+1;
                    q.push(g[u][i].F);
                }
        }
    }
}

int main(){
    fill(ans,ans+N,-1);
    cin>>n>>m;
    f(i,0,m){
        int u,v,t;
        Gett(u,v);
        gett(t);
        g[v].pb(mp(u,t));
    }
    bfs();
    if(dist[1]==N) cout<<-1<<'\n';
    else cout<<dist[1]<<'\n';
    f(i,1,n+1) cout<<(ans[i]==-1 ? 0 : ans[i]);
}