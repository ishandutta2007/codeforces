#include<bits/stdc++.h>
using namespace std;
const int maxk=5005,mod=1e9+7;
int s[maxk][maxk];
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
int main(){
    int n,k;
    n=read();k=read();
    s[0][0]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=i;j++)
            s[i][j]=add(1ll*j*s[i-1][j]%mod+s[i-1][j-1]);
    int ans=0,pw2=power(2,n-1),iv2=power(2,mod-2),fc=n;
    for(int i=1;i<=k;i++){
        ans=add(ans+1ll*s[k][i]*fc%mod*pw2%mod);
        fc=1ll*fc*(n-i)%mod;
        pw2=1ll*pw2*iv2%mod;
    }
    printf("%d\n",ans);
    return 0;
}