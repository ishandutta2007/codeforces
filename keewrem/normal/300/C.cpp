#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 ll aa,bb, N;
 const ll MAXN = 1000010;
 const ll MOD = 1000000007;
ll sum(ll a, ll b){
    while(a+b>MOD)a-=MOD;
    return a+b;
}
 
ll mult(ll a, ll b){
    return (a*b)%MOD;
}
 
ll fexp(ll base, ll exp){
    ll r = 1;
    for(ll i = 1; i <= exp; i<<=1){
        if(i&exp)r=mult(r,base);
        base=mult(base,base);
    }
    return r;
}
 
ll inv(ll a){
    return fexp(a,MOD-2);
}
 
ll fact[MAXN]; ll finv[MAXN];
void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++){
        fact[i]=mult(fact[i-1],i);
    }
    finv[MAXN-1]=inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i; i--){
        finv[i] = mult(finv[i+1],i);
    }
}
 
ll bin(ll a, ll b){
    if(a == b || b == 0)return 1;
    if(b > a)return 0;
    return mult(fact[a], mult(inv(fact[b]),inv(fact[a-b])));
}
 
 bool ig(ll k){
    while(k){
        if(k %10 != aa && k%10 != bb)return 1;
        k/=10;
    }
    return 0;
     
 }
 int main(){
     cin >> aa >> bb >> N;
     ll ans = 0;
     f_init();
     
     for(int i = 0; i <= N;i++){
         if(ig(aa*i+(N-i)*bb)){continue;}
         ans += bin(N,i);
       //  cout << bin(N,i)<< " ";
         ans%=MOD;
     }
     cout << ans;
 }