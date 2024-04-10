#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int mod=1e9+7;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
signed main(){
    int T;
    T=read();
    while(T--){
        ll n;
        n=read();
        ll p=1;
        int c=2,res=0;
        while(p<=n){
            ll num=(n/p);
            int d=c/gcd(c,p);
            res=add(res+1ll*(num-(num/d))%mod*c%mod);
            p=p*d;
            c++;
        }
        printf("%lld\n",res);
    }
    return 0;
}