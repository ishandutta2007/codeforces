#include<bits/stdc++.h>
const int N=200010;
using namespace std;
int n;
int a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
	scanf("%d",&a[i]);
    }
    sort(a+1,a+2*n+1);
    long long ans=1ll*(a[n*2]-a[n+1])*(a[n]-a[1]);
    for(int i=2;i<=n;i++){
	ans=min(ans,1ll*(a[n*2]-a[1])*(a[i+n-1]-a[i]));
    }
    printf("%I64d\n",ans);
    return 0;
}