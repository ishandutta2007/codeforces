#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=3e5+10;
int cct,cc[mn];
set<int>f[mn];
int p[mn];
int fi(int x){return x==p[x]?x:(p[x]=fi(p[x]));}
int n;
void dfs(int x){
    cc[x]=cct;
    p[x]=fi(x+1);
    for(int y=fi(2);y<=n;y=fi(y+1)){
        if(f[x].count(y))continue;
        dfs(y);
    }
}
void die(){
    printf("impossible");
    exit(0);
}
bool gud[mn];
int main(){
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        f[a].insert(b);
        f[b].insert(a);
    }
    iota(p,p+mn,0);
    for(int i=2;i<=n;i++)if(!cc[i])cct++,dfs(i);
    if(n-1-f[1].size()<k)die();
    for(int i=2;i<=n;i++)if(!f[1].count(i))gud[cc[i]]=1;
    for(int i=1;i<=cct;i++)if(!gud[i])die();
    if(cct>k)die();
    printf("possible");
}