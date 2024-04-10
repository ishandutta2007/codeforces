// remoe judge
#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005,P=998244353;
int n;
int deg[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        ++deg[u];
        ++deg[v];
    }
    int ans=n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=deg[i];++j)
            ans=1ll*ans*j%P;
    printf("%d\n",ans);
    return 0;
}