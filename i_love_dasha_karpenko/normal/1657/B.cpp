#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair

void solve() {
    int n,B,x,y;
    cin>>n>>B>>x>>y;
    ll res = 0;
    ll cur = 0;
    while(n--){
        if (cur+x<=B)
            cur+=x;
        else cur-=y;
        res+=cur;
    }
    cout<<res<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}