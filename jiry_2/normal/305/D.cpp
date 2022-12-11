#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,k,len,x[1000100],mo=1e9+7,pd[1000100];
int quick(int k1,int k2){
    int k3=1;
    while (k2){
        if (k2&1) k3=1ll*k3*k1%mo; k2=k2/2; k1=1ll*k1*k1%mo;
    }
    return k3;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); if (k1>k2) swap(k1,k2);
        if (k2-k1==k+1) {pd[k1]=1; x[++len]=k1;} else if (k2-k1!=k+1&&k2-k1!=1){cout<<0<<endl; return 0;}
    }
    sort(x+1,x+len+1);
    if (x[1]+k+1<=x[len]){cout<<0<<endl; return 0;}
    int ans=1,l=max(x[len]-k,1),r=x[1];
    if (len==0) {l=1; r=n-k-1;}
    for (int i=l;i<=r;i++){
        int k1=min(k,n-k-i-1)-len; if (pd[i]) k1++; ans=(ans+quick(2,k1))%mo; if (pd[i]) ans--;
    }
    cout<<(ans+mo)%mo<<endl;
}