#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,u,ans,tot,ch[110000][26];
char s[110000];
bool vis[110000];
priority_queue<int> que[110000];
void ins(){
    int now=0,len;
    len=strlen(s);
    for (int i=0;i<len;i++){
        if (!ch[now][s[i]-'a']) ch[now][s[i]-'a']=++tot;
        now=ch[now][s[i]-'a'];
    }
    vis[now]=true;
}
void dfs(int u,int dep){
    int v;
    for (int i=0;i<26;i++){
        v=ch[u][i];
        if (v){
            dfs(v,dep+1);
            if (que[v].size()>que[u].size()) swap(que[u],que[v]);
            while (!que[v].empty()){
                que[u].push(que[v].top());
                que[v].pop();
            }
        }
    }
    if (!vis[u]) que[u].pop();
    que[u].push(dep);
    return;
}
int main(){
    scanf("%d",&n); tot=0;
    for (int i=1;i<=n;i++){
        scanf("%s",s);
        ins();
    }
    for (int i=0;i<26;i++)
        if (ch[0][i]){
            u=ch[0][i];
            dfs(u,1);
            while (!que[u].empty()){
                ans+=que[u].top();
                que[u].pop();
            }
        }
    printf("%d\n",ans);
    return 0;
}