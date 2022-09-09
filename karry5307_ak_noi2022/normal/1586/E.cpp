#include<bits/stdc++.h>
using namespace std;
int n,m,q,fa[300010],dep[300010];
vector<int> G[300010];
bool vis[300010];
void dfs(int x,int F){
    // printf("%d %d\n",x,F);
    vis[x]=1;fa[x]=F;
    dep[x]=dep[F]+1;
    for(auto to:G[x]){
        if(vis[to]) continue;
        dfs(to,x);
    }
}
int cnt[300010];
vector<int> Ans[300010];
int ans;
bool dfs2(int x){
    int c=0;
    for(auto to:G[x]){
        if(to==fa[x]||fa[to]!=x) continue;
        c+=dfs2(to);
    }
    if(cnt[x]&1) ans++,c++;
    ans-=c/2;
    return (cnt[x]&1);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }dfs(1,0);int x,y;
    scanf("%d",&q);
    for(int ti=1;ti<=q;ti++){
        scanf("%d %d",&x,&y);int t=x;
        if(dep[x]<dep[y]) swap(x,y);
        vector<int> Ans1,Ans2;
        while(dep[x]>dep[y]) Ans1.push_back(x),cnt[x]++,x=fa[x];
        while(x!=y){
            cnt[x]++;cnt[y]++;
            Ans1.push_back(x);
            Ans2.push_back(y);
            x=fa[x];y=fa[y];
        }
        for(auto x:Ans1) Ans[ti].push_back(x);
        Ans[ti].push_back(x);reverse(Ans2.begin(),Ans2.end());
        for(auto x:Ans2) Ans[ti].push_back(x);
        if(Ans[ti][0]!=t) reverse(Ans[ti].begin(),Ans[ti].end());
    }
    bool pd=1;
    for(int i=1;i<=n;i++) if(cnt[i]&1) pd=0;
    if(pd){
        puts("YES");
        for(int i=1;i<=q;i++){
            printf("%d\n",(int)Ans[i].size());
            for(auto x:Ans[i]) printf("%d ",x);
            puts("");
        }
    }else{
        dfs2(1);
        printf("NO\n%d\n",ans);
    }
    return 0;
}