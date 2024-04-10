#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1, oo = 1e9;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> r(n+1);
        for(int i=0;i<n;++i) cin >> r[i];
        int m; cin >> m;
        vector<int> b(m+1);
        for(int i=0;i<m;++i) cin >> b[i];
        ll ans = 0;
        ll curr = 0;
        for(int i=0;i<=n;++i) {
            ll curb = 0;
            for(int j=0;j<=m;++j) {
                ans = max(ans,curr+curb);
                curb+=b[j];
            }
            curr+=r[i];
        }
        cout << ans << endl;
        
    }
}