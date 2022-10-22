#include <bits/stdc++.h>
using namespace std;
const int mn=230;
int a[mn],b[mn],c[mn],d[mn];
vector<int>nx,ny;
map<int,int>cx,cy;
vector<int>g[mn];
int cap[mn][mn],ind[mn],dep[mn];
int dfs(int x,int n,int big){
    if(n==x)return big;
    for(;ind[x]<g[x].size();ind[x]++){
        int y=g[x][ind[x]];
        if(dep[y]!=dep[x]+1||cap[x][y]<=0)continue;
        int v=dfs(y,n,min(big,cap[x][y]));
        if(v){
            cap[x][y]-=v;
            cap[y][x]+=v;
            return v;
        }
    }
    return 0;
}
bool bfs(int n){
    memset(dep,0x3f,sizeof(dep));
    memset(ind,0,sizeof(ind));
    dep[0]=0;
    queue<int>q;
    q.push(0);
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int y:g[x]){
            if(dep[y]==0x3f3f3f3f&&cap[x][y]>0)dep[y]=dep[x]+1,q.push(y);
        }
    }
    return dep[n]!=0x3f3f3f3f;
}
int maxflow(int n){

    int ans=0;
    while(bfs(n)){
        int d=-1;
        while(d){
            ans+=(d=dfs(0,n,0x3f3f3f3f));
        }
    }
    return ans;
}
int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
        nx.push_back(a[i]);
        nx.push_back(++c[i]);
        ny.push_back(b[i]);
        ny.push_back(++d[i]);
    }
    sort(nx.begin(),nx.end());
    sort(ny.begin(),ny.end());
    nx.resize(distance(nx.begin(),unique(nx.begin(),nx.end())));
    ny.resize(distance(ny.begin(),unique(ny.begin(),ny.end())));
    for(i=0;i<nx.size();i++){
        cx[nx[i]]=i+1;
        g[0].push_back(i+1);
        g[i+1].push_back(0);
        if(i<nx.size()-1)cap[0][i+1]=nx[i+1]-nx[i];
    }
    for(i=0;i<ny.size();i++){
        cy[ny[i]]=nx.size()+i+1;
        g[nx.size()+i+1].push_back(nx.size()+ny.size()+1);
        g[nx.size()+ny.size()+1].push_back(nx.size()+i+1);
        if(i<ny.size()-1)cap[nx.size()+i+1][nx.size()+ny.size()+1]=ny[i+1]-ny[i];
    }
    for(i=0;i<m;i++){
        a[i]=cx[a[i]],b[i]=cy[b[i]],c[i]=cx[c[i]],d[i]=cy[d[i]];
    }
    for(i=0;i<m;i++){
        for(j=a[i];j<c[i];j++){
            for(k=b[i];k<d[i];k++){
                g[j].push_back(k);
                g[k].push_back(j);
                cap[j][k]=0x3f3f3f3f;
            }
        }
    }
    printf("%d",maxflow(nx.size()+ny.size()+1));
}