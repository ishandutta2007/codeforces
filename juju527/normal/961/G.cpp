#include<bits/stdc++.h>
using namespace std;
const int maxk=2e5+5,mod=1e9+7;
int fc[maxk],iv[maxk];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
    if(x>=mod)x-=mod;
    return x;
}
int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
int S(int n,int k){
    int op=1,s=0;
    for(int i=0;i<=k;i++){
        s=add(s+1ll*op*iv[i]%mod*power(k-i,n)%mod*iv[k-i]%mod);
        op=mod-op;
    }
    return s;
}
int main(){
    int n,k,p=0,sum=0;
    n=read();k=read();
    fc[0]=1;
    for(int i=1;i<=k;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[k]=power(fc[k],mod-2);
    for(int i=k-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
    p=add(S(n,k)+1ll*(n-1)*S(n-1,k)%mod);
    for(int i=1;i<=n;i++)sum=add(sum+read());
    printf("%d\n",1ll*p*sum%mod);
    return 0;
}