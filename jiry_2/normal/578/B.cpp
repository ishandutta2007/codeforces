#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,x,where;
long long a[210000],b[210000],c[210000];
int main(){
    scanf("%d%d%d",&n,&k,&x);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    long long ans=0;
    for (int i=1;i<=n;i++) b[i]=(b[i-1]|a[i]);
    for (int i=n;i;i--) c[i]=(c[i+1]|a[i]);
    long long now=1;
    for (int i=1;i<=k;i++) now=now*x;
    for (int i=1;i<=n;i++){
        ans=max(ans,(a[i]*now)|b[i-1]|c[i+1]);
    }
    cout<<ans<<endl;
}