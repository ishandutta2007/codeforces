#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d;

vector<ll> oc, zc;

bool Try (ll X, ll Y) {
    if(X+Y == 0) return false;
    if(b+c != X*Y) return false;
    ll lft = b, zero = X, one = Y;
    while(zero || one) {
        if(zero && lft >= one) {printf("0"); zero--; lft -= one;}
        else {printf("1"); one--;}
    }
    puts(""); return true;
}

int main()
{
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(!a) {zc.push_back(0); zc.push_back(1);}
    else {
        for(ll i=2;;i++) {
            if(i*(i-1)/2>a) {puts("Impossible"); return 0;}
            if(i*(i-1)/2 == a) {zc.push_back(i); break;}
        }
    }
    if(!d) {oc.push_back(0); oc.push_back(1);}
    else {
        for(ll i=2;;i++) {
            if(i*(i-1)/2>d) {puts("Impossible"); return 0;}
            if(i*(i-1)/2 == d) {oc.push_back(i); break;}
        }
    }
    for(int i=0;i<zc.size();i++) {
        for(int j=0;j<oc.size();j++) {
            if(Try(zc[i], oc[j])) return 0;
        }
    }
    puts("Impossible");
}