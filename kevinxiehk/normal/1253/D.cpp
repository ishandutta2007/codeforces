#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200005
using namespace std;
bool vi[N];int grp[N],cnt=1;vector<int>edge[N];int grpsize[N];
void dfs(int a){
    vi[a]=true;
    grp[a]=cnt;
    grpsize[cnt]++;
    for(auto i:edge[a]){
        
        if(vi[i])continue;//cout<<i<<" "<<a<<endl;
        dfs(i);
    }
    return;
}
int main(){
    for(int i=0;i<=N;i++){vi[i]=false;grpsize[i]=0;}
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for(int i=0;i<=n;i++)grp[i]=-1;
    for(int i=1;i<=n;i++){
        if(grp[i]==-1){dfs(i);cnt++;}
        
    }
    for(int i=1;i<cnt;i++)grpsize[i]+=grpsize[i-1];
    //cout<<cnt-1<<endl;
    int ans=cnt-1;
    int tmax=0;
    for(int i=1;i<=n;i++){
        tmax=max(tmax,grp[i]);
        if(i==grpsize[tmax])ans--;
    }
    cout<<ans<<endl;
    return 0;
}