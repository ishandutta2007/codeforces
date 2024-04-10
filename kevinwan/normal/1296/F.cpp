#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=5010;
vector<int>g[mn],id[mn];
int ans[mn];
struct three{int a,b,c;bool operator<(const three&ot)const{return c<ot.c;}};
three p[mn];
int pain;
bool go(int x,int p,int t){
    if(x==t)return 1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i],ii=id[x][i];
        if(y==p)continue;
        if(go(y,x,t)){
            ans[ii]=pain;
            return 1;
        }
    }
    return 0;
}
int sm;
bool mi(int x,int p,int t){
    if(x==t)return 1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i],ii=id[x][i];
        if(y==p)continue;
        if(mi(y,x,t)){
            sm=min(sm,ans[ii]);
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        id[a].push_back(i);
        id[b].push_back(i);
        ans[i]=1;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
    sort(p,p+m);
    for(int i=0;i<m;i++){
        pain=p[i].c;
        go(p[i].a,0,p[i].b);
    }
    for(int i=0;i<m;i++){
        sm=0x3f3f3f3f;
        mi(p[i].a,0,p[i].b);
        if(sm!=p[i].c){
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<n-1;i++)printf("%d ",ans[i]);
}