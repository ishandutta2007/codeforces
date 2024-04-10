// remote judge
#include<bits/stdc++.h>
using namespace std;
const int MAXN=300000;
int n,k;
long long a[MAXN];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%I64d",&a[i]);
    for(int i=n-2;i>=0;--i)
        a[i]+=a[i+1];
    sort(a+1,a+n);
    long long ans=a[0];
    for(int i=n-k+1;i<n;++i)
        ans+=a[i];
    printf("%I64d\n",ans);
    return 0;
}