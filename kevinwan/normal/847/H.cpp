#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[100002];
ll inc[100002],ina[100002],de[100002],dea[100002];
int main() {
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    int at=0;
    for(i=1;i<=n;i++)inc[i]=inc[i-1]+max(0,at+1-a[i]),ina[i]=at=max(a[i],at+1);
    at=0;
    for(i=n;i>=1;i--)de[i]=de[i+1]+max(0,at+1-a[i]),dea[i]=at=max(a[i],at+1);
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(i=0;i<=n;i++)ans=min(ans,inc[i]+de[i+1]+(ina[i]==dea[i+1]));
    printf("%lld",ans);
}