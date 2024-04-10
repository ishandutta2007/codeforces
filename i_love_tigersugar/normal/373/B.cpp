#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
ll pw[22];
ll m,w,k;
int ndig(ll x) {
    FOR(i,1,111) if (pw[i]>x) return (i);
}
void process(void) {
    cin >> w >> m >> k;
    pw[0]=1LL;
    FOR(i,1,18) pw[i]=pw[i-1]*10;
    int nd=ndig(m);
    if (INF/(pw[nd]-m)<nd*k || (pw[nd]-m)*nd*k>w) {
        cout << w/(nd*k);
        return;
    }
    ll res=pw[nd]-m;
    w=w-(pw[nd]-m)*nd*k;
    FOR(i,nd+1,111) {
        if (INF/(i*k)>=9*pw[i-1] && w>=9*i*k*pw[i-1]) {
            w=w-9*i*k*pw[i-1];
            res+=9*pw[i-1];
        }
        else {
            res+=w/(i*k);
            break;
        }
    }
    cout << res;
}
int main(void) {
    ios::sync_with_stdio(true);
    process();
    return 0;
}