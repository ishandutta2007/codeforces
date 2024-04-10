#include<bits/stdc++.h>
using namespace std;
int n,a[210000];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0x3f3f3f3f;
    for (int i=1;i<=n/2;i++) ans=min(ans,a[i+n/2]-a[i]);
    printf("%d",ans);
    return 0;
}