#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxk=11000;
ll n,m; int k;
ll x,y,a[maxk],r[maxk];

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if (!b){
        x=1,y=0;
        return a;
    }
    ll g=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}
inline ll mul(ll x,ll y,ll Mod){
    ll ret=x*y-((ll)((long double)x/Mod*y+0.5))*Mod;
    return (ret%Mod+Mod)%Mod;
}
ll excrt(){
    ll M=a[1],R=r[1],x,y,d;
    for(int i=2;i<=k;i++){
        d=exgcd(M,a[i],x,y);
        if ((R-r[i])%d) return -1;
        x=mul((R-r[i])/d,x,a[i]);
        R-=M*x;
        M=M/d*a[i];
        R%=M;
    }
    return (R-1+M)%M+1;
}

int main(){
	scanf("%lld%lld%d",&n,&m,&k);
    scanf("%lld",&a[1]); r[1]=0; x=a[1];
    for (int i=2;i<=k;i++){
        scanf("%lld",&a[i]); r[i]=1-i;
        ll g=gcd(x,a[i]);
        x=x/g*a[i];
    }
    y=excrt();
    if (x>n||y+k-1>m||y<1){
        puts("NO");
        return 0;
    }
    for (int i=1;i<=k;i++)
        if (gcd(x,y+i-1)!=a[i]){
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}