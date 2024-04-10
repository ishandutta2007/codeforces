#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,a[20000],key[20000],ans[20000],x,y;
int k;
long long gcd(long long k1,long long k2,long long &x,long long &y){
    if (k2==0){x=1; y=0; return k1;}
    long long r=gcd(k2,k1%k2,y,x); y-=k1/k2*x; return r;
}
long long gcd(long long k1,long long k2){
    if (k2==0) return k1; return gcd(k2,k1%k2);
}
long long quick(long long k1,long long k2,long long mo){
    k1=(k1%mo+mo)%mo; k2=(k2%mo+mo)%mo;
    long long k3=0;
    while (k2){
        if (k2&1) k3=(k3+k1)%mo; k1=k1*2%mo; k2=k2/2;
    }
    return k3;
}
int main(){
    scanf("%I64d%I64d%d",&n,&m,&k); for (int i=1;i<=k;i++) scanf("%I64d",&a[i]);
    long long now=1;
    for (int i=1;i<=k;i++){
        long long d=gcd(a[i],now); now=now/d; if (now>n/a[i]){cout<<"NO"<<endl; return 0;} now=now*a[i];
    }
    for (int i=1;i<=k;i++) key[i]=a[i];
    for (int i=1;i<=k;i++) ans[i]=(1-i+a[i])%a[i];
    for (int i=2;i<=k;i++){
        long long r=gcd(key[i-1],-key[i],x,y);
        if ((ans[i]-ans[i-1])%abs(r)){cout<<"NO"<<endl; return 0;}
        key[i]=key[i-1]/abs(r)*key[i];
        ans[i]=quick(quick(x,((ans[i]-ans[i-1])/r),key[i]),key[i-1],key[i])+ans[i-1];
        ans[i]=(ans[i]%key[i]+key[i])%key[i]; 
    }
    if (ans[k]==0) ans[k]+=now;
    if (ans[k]>m-k+1) {cout<<"NO"<<endl; return 0;}
    for (int i=1;i<=k;i++) if (gcd(ans[k]+i-1,now)!=a[i]){cout<<"NO"<<endl; return 0;} cout<<"YES"<<endl;
}