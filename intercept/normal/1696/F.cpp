#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
int n;
int p[109][109][109];
int g[109][109];
char s[109];
bool vis[109];
bool sol(int x){
    queue<pii>q;
    q.push(make_pair(x,1));
    q.push(make_pair(1,x));
    for(int i=1;i<=n;++i){
        vis[i]=0;
        for(int j=1;j<=n;++j)g[i][j]=1e9;
    }
    g[1][x]=g[x][1]=1;
    vis[1]=vis[x]=1;
    for(int i=1;i<=n;++i)g[i][i]=0;
    while(!q.empty()){
        auto o=q.front();
        q.pop();
        int fa=o.fi,u=o.se;
        for(int v=1;v<=n;++v){
            if(v==u||v==fa)continue;
            if((p[fa][v][u]||p[v][fa][u])&&!vis[v]){
                vis[v]=1;
                g[v][u]=g[u][v]=1;
                q.push(make_pair(u,v));
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            if(g[i][j]==1e9)return 0;
            for(int k=1;k<=n;++k){
                if((g[i][k]==g[j][k])!=p[i][j][k]){
                    return 0;
                }
            }
        }
    }
    puts("YES");
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            if(g[i][j]==1)cout<<i<<" "<<j<<endl;
        }
    }
    return 1;
}
void work(){
    cin>>n;
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            cin>>(s+1);
            for(int k=1;k<=n;++k)p[i][j][k]=s[k]-'0';
        }
    }
    for(int i=2;i<=n;++i){
        if(sol(i))return;
    }
    puts("NO");
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
3
001 000
000
*/