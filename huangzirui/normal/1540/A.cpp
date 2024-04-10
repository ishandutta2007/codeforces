#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m,a[maxn];
long long ans=0;
int main(){
    int T;cin>>T;
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(i=2;i<=n;i++)ans+=1ll*a[i]*(n-i-1)-1ll*a[i]*(i-2);
        ans+=a[n];
        printf("%lld\n",ans);
    }
}