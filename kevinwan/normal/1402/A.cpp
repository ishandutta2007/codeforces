//#pragma comment(linker, "/STACK:2000000000")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
void gcd(ll n,ll m,ll c,ll&a,ll&b){
    if(!m)a=c/n,b=0;
    else{
        ll k=n/m,l=n%m,aa,bb;
        gcd(m,l,c,aa,bb);
        a=bb;
        b=aa-bb*k;
    }
}
ll a[mn],f[mn],s[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++){
        gcd(n,n-1,-a[i],f[i],s[i]);
    }
    printf("1 %d\n",n);
    printf("0 ");
    for(int i=2;i<=n;i++)printf("%lld ",f[i]*n);
    printf("\n");
    if(n>=2){
        printf("2 %d\n",n);
        for(int i=2;i<=n;i++)printf("%lld ",s[i]*(n-1));
    }
    else{
        printf("1 1\n0");
    }
    printf("\n");
    printf("1 1 \n%lld",-a[1]);
}