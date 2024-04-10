#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(), var.end()
#define mp make_pair
#define gp(x,y) ((x-1)*m+y-1)
const ll MAXN = 1e18+123;
ll rev(ll x){
    ll ans = 0;
    while(x){
        ans = (ans<<1)+(x&1);
        x = x>>1;
    }
    return ans;
}

ll addright(ll x){
    return rev(rev((x<<1)+1));
}
ll addleft(ll x){
    return rev((rev(x)<<1)+1);
}
void solve(){
    long long _x,_y;
    cin>>_x>>_y;
    ll x = _x,y = _y;

    for(ll bx = x;bx<=y;bx = addright(bx)){
        ll cx = bx;
        while(cx<y)
            cx = addleft(cx);
        if (cx==y){
            cout<<"YES\n";
            return;
        }
    }
    for(ll bx = rev(x);bx<=y;bx = addright(bx)){
        ll cx = bx;
        while(cx<y)
            cx = addleft(cx);
        if (cx==y){
            cout<<"YES\n";
            return;
        }
    }
    for(ll bx = rev(rev(x));bx<=y;bx = addright(bx)){
        ll cx = bx;
        while(cx<y)
            cx = addleft(cx);
        if (cx==y){
            cout<<"YES\n";
            return;
        }
    }
    for(ll bx = rev(addright(x));bx<=y;bx = addright(bx)){
        ll cx = bx;
        while(cx<y)
            cx = addleft(cx);
        if (cx==y){
            cout<<"YES\n";
            return;
        }
    }
    if (x==y){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}