//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;

void solve(){
    ll a,b,x;
    cin>>a>>b>>x;
    int flag = 0;
    while(a && b){
        if (a<b)
            swap(a,b);
        ll k = a/b;
        if ((a-x)%b==0){
            ll need = (a-x)/b;
            if (0<=need && need<=k){
                flag = 1;
                break;
            }
        }
        a-=k*b;
    }
    if (flag)
        cout<<"YES\n";
    else cout<<"NO\n";

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}