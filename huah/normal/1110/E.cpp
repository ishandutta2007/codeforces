#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[100001],b[100001],aa[100001],bb[100001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    if(a[1]!=b[1]||a[n]!=b[n]){printf("NO\n");return 0;}
    for(int i=2;i<=n;i++) aa[i]=a[i]-a[i-1],bb[i]=b[i]-b[i-1];
    sort(aa+2,aa+2+n);
    sort(bb+2,bb+2+n);
    bool flag=true;
    for(int i=2;i<=n;i++)
        if(aa[i]!=bb[i])
            {flag=false;break;}
    printf(flag?"YES":"NO");
}