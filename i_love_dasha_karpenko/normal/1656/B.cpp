#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair

void solve() {
    int n,k;
    cin>>n>>k;
    set<int> S;
    bool flag = 0;
    map<int,int> M;
    for(int i = 1;i<=n;++i){
        int val; cin>>val;
        M[val]++;
    }
    for(auto [to,qnt]:M){
        if (to-k==to)
            flag = max(flag,qnt>1);
        else flag = max(flag,bool(M.count(to-k)));
    }
    cout<<(flag?"YES\n":"NO\n");
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}