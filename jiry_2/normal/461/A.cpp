#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long long x[400000];
int main(){
    int n; scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&x[i]); sort(x+1,x+n+1);
    long long ans=0;
    if (n==1){cout<<x[1]<<endl; return 0;}
    for (int i=1;i<=n;i++) ans+=1ll*(i+1)*x[i]; ans-=x[n]; cout<<ans<<endl;
    return 0;
}