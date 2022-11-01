//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
ll gcd(ll a,ll b,ll &k1,ll &k2){
    if (a==0 || b==0){
        if (a==0)
            k2 = 1,k1 = 0;
        else k1 = 1,k2 = 0;
        return a+b;
    }
    ll ka,kb;
    ll g = gcd(b%a,a,ka,kb);
    k1 = kb-b/a*ka;
    k2 = ka;
    return g;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a1,a2,b1,b2,L,R;
    cin>>a1>>b1>>a2>>b2>>L>>R;
    ll x,y;
    ll g = gcd(a1,a2,x,y);
    if ((b2-b1)%g){
        cout<<"0\n";
        return 0;
    }
    ll scale = (b2-b1)/g;
    x*=scale;
    y*=scale;
    ll mod = a2/g;
    x%=mod;
    if (x<0)
        x+=mod;
    x = x*a1+b1;
    ll step = a1/g*a2;
    if (x>L){
        ll dif = (x-L)/step;
        x-=dif*step;
    }
    if (x<L){
        ll dif = (L-x)/step+((L-x)%step!=0);
        x+=dif*step;
    }
    if (x<b1){
        ll dif = (b1-x)/step+((b1-x)%step!=0);
        x+=dif*step;
    }
    if (x<b2){
        ll dif = (b2-x)/step+((b2-x)%step!=0);
        x+=dif*step;
    }
    ll ans = 0;
    if (x<=R){
        ans = (R-x)/step+1;
    }
    cout<<ans<<endl;
    return 0;
}