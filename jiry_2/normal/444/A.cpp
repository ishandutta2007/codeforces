#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int x[600];
int main(){
    long double ans=0;
    int n,m; scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    for (int i=1;i<=m;i++){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); ans=max(ans,(long double)(x[k1]+x[k2])/(long double)k3);
    }
    printf("%.13lf\n",(double)ans);
    return 0;
}