#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a'+1)
const int MOD = 1e9+7;

ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll rev(ll x){
    return binpow(x,MOD-2);
}
#define bp binpow
void solve(){
    int n,m;
    cin>>n>>m;
    pair<int,int> start,finish;
    cin>>start.first>>start.second>>finish.first>>finish.second;
    ll p;
    cin>>p;
    int dx = 1,dy = 1;
    ll d1 = 2*m-2,d2 = 2*n-2;
    int steps = d1/__gcd(d1,d2)*d2;

    ll s = steps;
    ll tt = 0;
    while(steps--){

        if (start.first==finish.first || start.second==finish.second) {
            ++tt;
        }
        if (start.first+dx<1 || start.first+dx>n)
            dx = -dx;
        if (start.second+dy<1 || start.second+dy>m)
            dy = -dy;
        start.first+=dx;
        start.second+=dy;
    }
    steps = s;
    ll res = 0;
    p = p*rev(100)%MOD;
    ll q = (1-p+MOD)%MOD;
    ll b = 1;
    ll t = 0;
    while(steps--){

        if (start.first==finish.first || start.second==finish.second) {
            ++t;
            ll add1 = b*bp(q,t-1)%MOD*p%MOD*rev(MOD+1-bp(q,tt))%MOD;
            //ll v1 = (p*4)%MOD,v2 = (q*4)%MOD,v3 = add1*175%MOD;
            ll add2 = bp(q,t+tt-1)*p%MOD*s%MOD*rev(bp(MOD+1-bp(q,tt),2))%MOD;
            res = (res+add1+add2)%MOD;
        }
        if (start.first+dx<1 || start.first+dx>n)
            dx = -dx;
        if (start.second+dy<1 || start.second+dy>m)
            dy = -dy;
        start.first+=dx;
        start.second+=dy;
        ++b;
    }
    cout<<(res-1)%MOD<<endl;
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}