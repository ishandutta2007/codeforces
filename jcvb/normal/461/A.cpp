#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

int n;
typedef long long ll;
ll ans=0;
int a[500005];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ans+=1ll*n*a[n];
    for (int i=n-1;i>=1;i--)ans+=1ll*(i+1)*a[i];
    cout<<ans<<endl;
    return 0;
}