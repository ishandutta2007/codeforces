#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int INF = 1e18;

void solve() {
    int n;
    cin>>n;
    ll cl = INF,cr = -INF,lmin = INF,rmin = INF;
    ll res = INF;
    for(int i = 1;i<=n;++i){
        ll l,r,cost;
        cin>>l>>r>>cost;
        if (cl>l || cr<r){
            res = INF;
            if (cl>l)
                lmin = INF;
            if (cr<r)
                rmin = INF;
        }
        cl = min(cl,l);
        cr = max(cr,r);
        if (l==cl)
            lmin = min(lmin,cost);
        if (r==cr)
            rmin = min(rmin,cost);
        if (l==cl && cr==r)
            res = min(res,cost);
        res = min(res,lmin+rmin);
        cout<<res<<'\n';
    }
    //cout<<endl;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}