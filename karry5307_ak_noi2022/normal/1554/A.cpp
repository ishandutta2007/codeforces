#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,1ll*a[i]*a[i+1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}