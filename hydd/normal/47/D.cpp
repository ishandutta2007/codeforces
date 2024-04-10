#include<bits/stdc++.h>
using namespace std;
int n,m,k[25],ans;
char s[25][45];
void dfs(int u){
    if (u==n){
        for (int i=1;i<=m;i++)
            if (k[i]!=0) return;
        ans++;
        return;
    }
    for (int i=1;i<=m;i++)
        if (k[i]<0) return;
    for (int i=1;i<=m;i++)
        if (s[i][u]=='0') k[i]--;
    dfs(u+1);
    for (int i=1;i<=m;i++)
        if (s[i][u]=='0') k[i]++;
        else k[i]--;
    dfs(u+1);
    for (int i=1;i<=m;i++)
        if (s[i][u]=='1') k[i]++;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%s",s[i]);
        scanf("%d",&k[i]);
    }
    dfs(0); printf("%d\n",ans);
    return 0;
}