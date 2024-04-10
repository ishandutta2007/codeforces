#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[301000];
long long Mod = 998244353, sum;
long long Pow(long long a, int b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n+n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+n+1);
    for(i=1;i<=n;i++)sum+=w[n+i]-w[i];
    sum%=Mod;
    long long t=1;
    for(i=1;i<=n;i++){
        t=t*(2*n-i+1)%Mod;
        t=t*Pow(i,Mod-2)%Mod;
    }
    printf("%lld\n",sum*t%Mod);
}