#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 1e4+1;
void solve() {
    int n,k; cin >> n >> k;
    int a[mxN];
    int mx=0;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    if(mx > k) {
        cout << "0\n";
        return;
    }
    sort(a,a+n);
    int ans = 0;
    for(int i=1;i<n;++i) {
        ans+=(k-a[i])/a[0];
    }
    cout << ans << endl;

}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}