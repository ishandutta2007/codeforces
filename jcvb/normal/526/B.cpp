#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define mo 1000000007
typedef long long ll;
int qp(int a,int b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);
    return ans;
}




int k;
int n;
int a[111111];
int su[111111];
int main()
{
    scanf("%d",&k);
    n=(1<<k+1)-1;
    for (int i=2;i<=n;i++)scanf("%d",&a[i]);
    int ans=0;
    for (int i=n/2;i>=1;i--){
        su[i]=max(su[i<<1]+a[i<<1],su[i<<1|1]+a[i<<1|1]);
        ans+=abs(a[i<<1]+su[i<<1]-a[i<<1|1]-su[i<<1|1]);
    }
    printf("%d\n",ans);
}