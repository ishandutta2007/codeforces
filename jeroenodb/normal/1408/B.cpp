#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 101;
void solve() {
    int a[mxN],n,k; cin >> n >> k;
    int different = 1;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        if(i and a[i]!=a[i-1]) {
            ++different;
        }
    }
    if(different<k) {
        cout << "1\n";
        return;
    }
    if(different>1 and k<2) {
        cout << "-1\n";
        return;
    }
    int difs = 1;
    int ans = 0;
    for(int i=1;i<n;++i) {
        if(a[i]==a[i-1]) continue;
        if(difs==k) {
            difs=1;
            ans++;
        }
        difs++;
    }
    if(difs) ans++;
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}