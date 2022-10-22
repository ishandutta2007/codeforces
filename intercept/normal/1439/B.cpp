#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=1e5+9;
int n,m,k;
vector<int>g[M];
int vis[M],du[M],d[M];
void work(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)g[i].clear(),du[i]=0,d[i]=i;
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v);
        g[v].eb(u);
        du[u]++;
        du[v]++;
    }
    for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end());
    queue<int>q;
    sort(d+1,d+n+1,[&](const int&l,const int&r){return g[l].size()<g[r].size();});
    for(int i=1;i<=n;++i){
        if(du[d[i]]<k)q.push(d[i]);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(du[u]==k-1){
            int num=0;
            vis[++num]=u;
            for(auto v:g[u])if(du[v]>=k-1)vis[++num]=v;
            bool flag=0;
            if(num<k)flag=1;
            if(!flag){
                for(int i=1;i<=num;++i){
                    for(int j=i+1;j<=num;++j){
                        if(!binary_search(g[vis[i]].begin(),g[vis[i]].end(),vis[j])){
                            flag=1;
                            break;
                        }
                    }
                    if(flag)break;
                }
            }
            if(!flag){
                puts("2");
                for(int i=1;i<=num;++i){
                    printf("%d ",vis[i]);
                }
                puts("");
                return;
            }
        }
        for(auto v:g[u]){
            du[v]--;
            if(du[v]==k-1)q.push(v);
        }
        du[u]=0;
    }
    int num=0;
    for(int i=1;i<=n;++i){
        num+=(du[i]>=k);
    }
    if(num){  
        printf("1 %d\n",num);
        for(int i=1;i<=n;++i){
            if(du[i]>=k)printf("%d ",i);
        }
        puts("");
        return;
    }
    puts("-1");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
1
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
*/