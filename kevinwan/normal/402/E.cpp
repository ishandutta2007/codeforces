#include<bits/stdc++.h>
using namespace std;
const int mn=2e3+10;
vector<int>g[mn];
int o[mn],ll[mn];
stack<int>s;
bool vis[mn],ins[mn];
int cnt,sct;
void dfs(int x){
    ll[x]=o[x]=cnt++;
    vis[x]=ins[x]=1;
    s.push(x);
    for(int y:g[x]){
        if(!vis[y])dfs(y),ll[x]=min(ll[x],ll[y]);
        else if(ins[y])ll[x]=min(ll[x],o[y]);
    }
    if(ll[x]==o[x]){
        while(s.top()!=x)ins[s.top()]=0,s.pop();
        ins[x]=0,s.pop();
        sct++;
    }
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int x;
            scanf("%d",&x);
            if(x)g[i].push_back(j);
        }
    }
    dfs(0);
    bool gud=(sct<=1);
    for(i=0;i<n;i++)gud&=vis[i];
    if(gud)printf("YES");
    else printf("NO");
}