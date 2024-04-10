#include<bits/stdc++.h>
using namespace std;
const int mn=3e2+10;
vector<int>g[mn];
int a[mn],b[mn];
bool inc(int a,int b,int c){return a<b&&b<c;}
bool vis[mn];
int col[mn];
bool ded;
void dfs(int x){
    vis[x]=1;
    for(int y:g[x]){
        if(vis[y]){
            if(col[y]!=col[x]^1)ded=1;
        }
        else col[y]=col[x]^1,dfs(y);
    }
}
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",a+i,b+i);
        if(a[i]>b[i])swap(a[i],b[i]);
    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if((inc(a[i],a[j],b[i])&&!inc(a[i]-1,b[j],b[i]+1))||
            (!inc(a[i]-1,a[j],b[i]+1)&&inc(a[i],b[j],b[i])))g[i].push_back(j),g[j].push_back(i);

        }
    }
    for(i=0;i<m;i++)if(!vis[i])dfs(i);
    if(ded)printf("Impossible");
    else for(i=0;i<m;i++)printf("%c",col[i]?'i':'o');
}