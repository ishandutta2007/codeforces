#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 101;
void solve() {
    int a[mxN][mxN],n,m; cin >> n >> m;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin >> a[i][j];
        }
    }
    long long ans=0;
    
    for(int i=0;i<n/2;++i) {
        for(int j=0;j<m/2;++j) {
            int tmp[4] = {a[i][j],a[n-i-1][j],a[n-i-1][m-j-1],a[i][m-j-1]};
            long long mn = 1e18;
            for(int k=0;k<4;++k) {
                int tmp2 = tmp[k];
                long long curans=0;
                for(int l: tmp) {
                    curans+=abs(l-tmp2);
                }
                mn = min(curans,mn);
            }
            ans+=mn;
        }
    }
    if(n%2==1) {
        for(int j=0;j<m/2;++j) {
            ans+=abs(a[n/2][j]-a[n/2][m-j-1]);
        }
    }
    if(m%2==1) {
        for(int j=0;j<n/2;++j) {
            ans+=abs(a[j][m/2]-a[n-j-1][m/2]);
        }
    }
    cout << ans << endl;
    
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}