#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e6+10;
const ll mod=1e9+7;
ll a[8];
bool gud[9][18000];
int main() {
    int lcm=840;
    ll n,ex=0;
    scanf("%lld",&n);
    for(int i=0;i<8;i++)scanf("%lld",a+i);
    ll sum=0;
    for(int i=0;i<8;i++)sum+=(i+1)*a[i];
    if(sum<=n){
        printf("%lld",sum);
        return 0;
    }
    for(int i=0;i<8;i++){
        ll x=a[i]%(lcm/(i+1));
        if(x!=a[i])x+=lcm/(i+1);
        ex+=(a[i]-x)/(lcm/(i+1));
        a[i]=x;
    }
    gud[0][0]=1;
    for(int i=0;i<8;i++){
        for(int j=0;j<=a[i];j++){
            for(int k=0;k+(i+1)*j<18000;k++){
                gud[i+1][k+(i+1)*j]|=gud[i][k];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<18000;i++){
        if(i>n||!gud[8][i])continue;
        ll wa=(n-i)/lcm;
        wa=min(wa,ex);
        ll pro=i+wa*lcm;
        ans=max(ans,pro);
    }
    printf("%lld",ans);
}