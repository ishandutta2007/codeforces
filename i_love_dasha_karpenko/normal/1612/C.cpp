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
    ll k,x;
    cin>>k>>x;
    ll l = 1,r = (k<<1)-1;
    while(l!=r){
        ll tm = (l+r)>>1;
        ll symbs = 0;
        if (tm>k){
            symbs += k*(k+1)-k;
            ll lf = ((k<<1)-1)-tm;
            symbs -= (lf*(lf+1))>>1;
        }
        else{
            symbs += ((tm+1)*tm)>>1;
        }
        if (symbs<x)
            l = tm+1;
        else r = tm;
    }
    cout<<l<<endl;
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