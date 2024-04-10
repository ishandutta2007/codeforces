#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int mn=1e4+10;
const lll ONE=1;
ll a[mn];
ll ggcd(ll a,ll b){
    while(b)a%=b,swap(a,b);
    return a;
}
void ct(ll n,ll m,ll c,ll&a,ll&b){
    if(!m)a=c/n,b=0;
    else{
        ll k=n/m,l=n%m,aa,bb;
        ct(m,l,c,aa,bb);
        a=-bb;
        b=-(aa+ONE*bb*k);
    }
}
lll crt(ll n,ll m,ll c,ll d){
    if(n<m)swap(n,m),swap(c,d);
    ll a,b;
    ct(n,m,d-c,a,b);
    return ONE*a*n+c;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    crt(3,5,4,6);
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)cin>>a[i];
    lll l=1,v=0;
    for(int i=0;i<k;i++){
        lll x=crt(l,a[i],v,-i);
        l=l/ggcd(l,a[i])*a[i];
        if(l>n){
            printf("NO\n");
            return 0;
        }
        x%=l;
        if(x<0)x+=l;
        v=x;
    }
    if(v<=0)v+=l;
    bool gud=1;
    if(v+k-1>m)gud=0;
    for(int i=0;i<k;i++){
        if(ggcd(v+i,l)!=a[i])gud=0;
    }
    printf("%s",gud?"YES":"NO");
}