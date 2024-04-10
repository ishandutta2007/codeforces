#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int INF = 1e9+7;

void solve() {
    int n;
    cin>>n;
    pair<int,int> mi = {INF,0},mx = {-INF,0};
    for(int i = 1;i<=n;++i){
        int val; cin>>val; mi = min(mi,{val,i}),mx = max(mx,{val,i});
    }
    cout<<mi.second<<' '<<mx.second<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}