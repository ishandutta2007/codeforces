#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
    return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int s = 0;
        for(int i = 0; i<m; i++){
            int x,y,w;
            cin >> x >> y >> w;
            s = (s|w);
        }
        cout << modpow(2,n-1)*s%mod << "\n";
    }
    return 0;
}