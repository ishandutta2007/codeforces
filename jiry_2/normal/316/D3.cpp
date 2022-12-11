#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int mo=1e9+7,n,m,len,I[2000000];
int main(){
    scanf("%d",&len); for (int i=1;i<=len;i++){int k1; scanf("%d",&k1); if (k1==1) n++; else m++;}
    int ans=0; I[1]=1; I[2]=2; I[0]=1;
    for (int i=3;i<=n;i++) I[i]=(I[i-1]+1ll*I[i-2]*(i-1))%mo;
    ans=I[n];
    for (int i=n+1;i<=n+m;i++) ans=1ll*ans*i%mo; cout<<ans<<endl;
}