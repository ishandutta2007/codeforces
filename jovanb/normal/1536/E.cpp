#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

void solve(){
    int n, m;
    cin >> n >> m;
    int res = 1;
    int nema = 1;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(auto c : s){
            if(c == '#') res = (res*2)%MOD;
            else nema = 0;
        }
    }
    cout << (res+MOD-nema)%MOD << "\n";
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