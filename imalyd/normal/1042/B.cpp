//Problem B
#include<bits/stdc++.h>
using namespace std;

int n,c[9],ans=-1;
void dfs(int v,int typ,int cost){
    if(v==8){if(typ==7&&(ans==-1||cost<ans))ans=cost;return;}
    dfs(v+1,typ,cost);
    if(c[v]!=-1)dfs(v+1,typ|v,cost+c[v]);
}
int main(){
    memset(c,-1,sizeof(c));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int pri,typ=0;char str[5];
        scanf("%d%s",&pri,str);
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='A')typ|=1;
            if(str[i]=='B')typ|=2;
            if(str[i]=='C')typ|=4;
        }
        if(c[typ]==-1||pri<c[typ])c[typ]=pri;
    }
    dfs(1,0,0);
    printf("%d",ans);
    return 0;
}