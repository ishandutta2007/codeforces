#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[310000],dp1[310000],dp2[310000],ans[310000];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans[1]=max(ans[1],a[i]);
    }
    for (int i=1;i<n;i++) dp1[min(i,n-i)]=max(dp1[min(i,n-i)],max(a[i],a[i+1]));
    for (int i=2;i<n;i++) dp2[min(i-1,n-i)]=max(dp2[min(i-1,n-i)],max(min(a[i-1],a[i]),min(a[i],a[i+1])));
    for (int i=n/2;i>=1;i--){
        ans[i<<1]=max(ans[(i+1)<<1],dp1[i]);
        ans[i<<1|1]=max(ans[(i+1)<<1|1],dp2[i]);
    }
    for (int i=n;i>=1;i--) printf("%d ",ans[i]);
    return 0;
}