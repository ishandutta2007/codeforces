#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef long double ld;
ll mod=1e9+7;
const ld pi=acos(-1.L);
const ld eps=3e-17;
const int mn=2e3+10;
vector<int>g[mn],ord[mn];
int c[mn];
void die(){printf("NO");exit(0);}
void dfs(int x,int p){
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        for(int z:ord[y])ord[x].push_back(z);
    }
    if(c[x]>ord[x].size())die();
    ord[x].insert(ord[x].begin()+c[x],x);
}
int ans[mn];
int main(){
    int n,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d%d",&p,c+i);
        if(p)g[p].push_back(i);
        else r=i;
    }
    dfs(r,0);
    for(int i=0;i<n;i++)ans[ord[r][i]]=i+1;
    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}