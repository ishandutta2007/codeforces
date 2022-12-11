#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long mo;
long long quick(long long x,long long y){return (x*y-(long long)(x/(long double)mo*y+1e-3)*mo+mo)%mo;}
long long get(int k){
    unsigned long long k1=1ll*k*(k+1)/2,k2=k*2+1;
    if (k1%3==0) k1/=3; else k2/=3; k1=k1%mo;
    return quick(k1,k2)%mo;
}
long long get(int k1,int k2){
    if (k1==0||k2==0) return 0;
    int k5=min(k1,k2);
    long long k3=1ll*k5*k5,k4=k3+1; if (k3%2==0) k3=k3/2; else k4=k4/2; k3%=mo; k4%=mo; k3=quick(k3,k4); 
    if (k1<k2){
        k4=(1ll*k1*(k1+1)/2)%mo; k4=quick(k4,(k2-k1))%mo; k3=((k4+quick((get(k2-1)-get(k1-1)+mo),k1)%mo+k3)%mo+mo)%mo;
    } else if (k1>k2){
        k4=(1ll*k2*(k2-1)/2)%mo; k4=quick(k4,(k1-k2))%mo; k3=((k3-k4+quick((get(k1)-get(k2)),k2))%mo+mo)%mo;
    }
    return k3;
}
int main(){
    int t; scanf("%d",&t);
    for (;t;t--){
        int k1,k2,k3,k4; scanf("%d%d%d%d",&k1,&k2,&k3,&k4); mo=1e10;
        long long ans1=(get(k1-1,k2-1)+get(k3,k4)-get(k1-1,k4)-get(k3,k2-1)+mo*4)%mo; mo++;
        long long ans2=(get(k1-1,k2-1)+get(k3,k4)-get(k1-1,k4)-get(k3,k2-1)+mo*4)%mo;
        if (ans1==ans2) printf("%I64d\n",ans1); else printf("...%010I64d\n",ans1);
    }
    return 0;
}