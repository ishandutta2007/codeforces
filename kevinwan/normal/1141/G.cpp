#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
pii ed[mn];
int com[mn],num;
vector<int>g[mn];
inline int ot(int&x,pii&p){return x^p.first^p.second;}
void dfs(int x,int p){
    int u=0;
    for(int h:g[x]){
        int y=ot(x,ed[h]);
        if(y==p)u=com[h];
    }
    int cur=1;
    for(int h:g[x]){
        int y=ot(x,ed[h]);
        if(cur==u)cur++;
        if(y!=p)com[h]=min(cur++,num),dfs(y,x);
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ed[i]={a,b};
        g[a].push_back(i);
        g[b].push_back(i);
    }
    vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(g[i].size());
    sort(v.begin(),v.end(),greater<int>());
    num=v[k];
    dfs(1,0);
    printf("%d\n",num);
    for(int i=0;i<n-1;i++)printf("%d ",com[i]);
}