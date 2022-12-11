#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int a,b;
    void scan(){
        scanf("%d%d",&a,&b);
    }
}x[2100];
int n,m,K;
int compare(point k1,point k2){
    return k1.a<k2.a||(k1.a==k2.a&&k1.b<k2.b);
}
const int mo=1e9+7;
int I[210000],nI[210000],dp[2100][2];
int C(int k1,int k2){
    return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int quick(int k1,int k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
    }
    return k3;
}
int main(){
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=K;i++) x[i].scan();
    K++; x[K]=(point){1,1};
    K++; x[K]=(point){n,m};
    sort(x+1,x+K+1,compare); I[0]=1;
    for (int i=1;i<=n+m;i++) I[i]=1ll*i*I[i-1]%mo;
    nI[0]=1; for (int i=1;i<=n+m;i++) nI[i]=1ll*nI[i-1]*quick(i,mo-2)%mo;
    dp[1][1]=1;
    for (int i=1;i<K;i++)
        for (int j=i+1;j<=K;j++)
            if (x[j].a>=x[i].a&&x[j].b>=x[i].b){
                for (int k=0;k<2;k++) dp[j][k^1]=(dp[j][k^1]+1ll*C(x[j].a-x[i].a+x[j].b-x[i].b,x[j].a-x[i].a)*dp[i][k])%mo;
            }
    cout<<(dp[K][0]-dp[K][1]+mo)%mo<<endl;
    return 0;
}