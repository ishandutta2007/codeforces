#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=2e5+5,inf=1e9+5;
int arr[maxn],occ[maxn];
int main(){
    int tt;
    int i,n;
    int ans,tmp;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d",&n);
        for (i=0;i<=n;i++) occ[i]=-inf;
        ans=inf;
        for (i=0;i<n;i++){
            scanf("%d",&arr[i]);
            tmp=i-occ[arr[i]]+1;
            if (tmp>=2) ans=min(ans,tmp);
            occ[arr[i]]=i;
        }
        if (ans>inf/2) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}