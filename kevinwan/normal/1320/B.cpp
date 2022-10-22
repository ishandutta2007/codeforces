#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
vector<int>g[mn],r[mn];
int dis[mn],p[mn];
int n,m,l,s,t;
int solvemin(){
    int ans=0;
    for(int i=0;i<l-1;i++){
        if(dis[p[i+1]]!=dis[p[i]]-1)ans++;
    }
    return ans;
}
int solvemax(){
    int ans=0;
    for(int i=0;i<l-1;i++){
        for(int j:g[p[i]]){
            if(j!=p[i+1]&&dis[j]==dis[p[i]]-1){
                ans++;
                break;
            }
        }
    }
    return ans;
}
int main()
{

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        r[b].push_back(a);
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        scanf("%d",p+i);
    }
    s=p[0],t=p[l-1];
    dis[t]=0;
    queue<int>q;
    q.push(t);
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int y:r[x]){
            if(dis[y]==0x3f3f3f3f){
                dis[y]=dis[x]+1;
                q.push(y);
            }
        }
    }
    printf("%d %d",solvemin(),solvemax());
}