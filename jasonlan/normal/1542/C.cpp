#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll n;
inline ll read(){
    ll res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
ll gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}
void proc(){
    n=read();
    ll res=n%mod,res2=1;
    for(ll i=1;i<=n;++i){
        res2=res2/gcd(res2,i)*i;
        if(res2>n)break;
        res=(res+(n/res2))%mod;
    }
    printf("%lld\n",res);
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}