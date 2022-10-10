#include <bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,ans,a[300010];
int main() {
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(i=1;i<=n/2;i++)
        ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    cout<<ans;
	return 0;
}