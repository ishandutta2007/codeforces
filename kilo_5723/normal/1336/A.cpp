#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
vector<int> e[maxn];
int a[maxn];
int dfs(int u,int f,int d){
    int siz=1;
    for (auto v:e[u]) if (v!=f)
        siz+=dfs(v,u,d+1);
    a[u]=d-siz;
    return siz;
}
int main(){
    int i,n,k;
    int u,v;
    ll ans;
    scanf("%d%d",&n,&k);
    for (i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1,1);
    sort(a+1,a+n+1);
    ans=0;
    for (i=0;i<k;i++) ans+=a[n-i];
    printf("%lld\n",ans);
    return 0;
}