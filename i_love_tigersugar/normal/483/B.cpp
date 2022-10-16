#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7;
ll x,y,cntx,cnty;
bool ok(ll v) {
    ll allx=v-v/x;
    ll ally=v-v/y;
    ll alls=v-v/(x*y);
    return (allx>=cntx && ally>=cnty && alls>=cntx+cnty);
}
ll answer(void) {
    ll L=0;
    ll R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(L)?L:R);
        ll M=(L+R)>>1;
        if (ok(M)) R=M; else L=M+1;
    }
}
int main(void) {
    cin>>cntx>>cnty>>x>>y;
    cout<<answer();
    return 0;
}