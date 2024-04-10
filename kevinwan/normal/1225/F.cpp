#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int mn=5e5+10;
int p[mn],dep[mn],sc[mn];
vector<int>g[mn];
vector<int>v,ans;
void dfs1(int x){
    sc[x]=dep[x];
    for(int y:g[x]){
        dep[y]=dep[x]+1;
        dfs1(y);
        sc[x]=max(sc[x],sc[y]);
    }
    sort(g[x].begin(),g[x].end(),[](int a,int b){return sc[a]<sc[b];});
}
void dfs2(int x){
    v.push_back(x);
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        dfs2(y);
        if(i+1<g[x].size()){
            int z=g[x][i+1];
            for(int j=sc[y];j>dep[x];j--){
                ans.push_back(z);
            }
        }
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)cin>>p[i],g[p[i]].push_back(i);
    dfs1(0);
    dfs2(0);
    for(int x:v)printf("%d ",x);
    printf("\n");
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}