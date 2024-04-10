#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <int, int> occ;

void solve(){
    int n;
    cin >> n;
    int d = 0;
    occ.clear();
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        occ[x]++;
        if(occ[x] > occ[d]) d = x;
    }
    int k = occ[d];
    int res = 0;
    while(k < n){
        res++;
        res += min(n - k, k);
        k *= 2;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}