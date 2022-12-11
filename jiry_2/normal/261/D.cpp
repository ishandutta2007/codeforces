#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100005],k,n,lim,t,a[100005];
int main(){
    scanf("%d%d%d%d",&k,&n,&lim,&t); t=min(t,lim);
    for (;k;k--){
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(f,0x00,sizeof f);
        for (int i=1;i<=n*t;i++){
            int k1=a[(i-1)%n+1],k2=f[k1]+1;
            for (int j=k1+1;j<=lim+1&&k2>f[j];j++) f[j]=k2;
        }
        cout<<f[lim+1]<<endl;
    }
    return 0;
}