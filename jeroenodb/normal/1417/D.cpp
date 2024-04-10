#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
const int mxN = 1e4+1;

void solve() {
    int n,a[mxN];
    cin >> n;
    int sum=0;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        sum+=a[i];
    }
    if(sum%n!=0) {
        cout << "-1\n";
        return;
    }
    int musthave = sum/n;
    vector<array<int,3>> ans;
    auto go = [&] (int i, int j, int x) {
        ans.push_back({i,j,x});
        a[i] -= i*x;
        a[j] += i*x;
    };
    for(int i=2;i<=n;++i) {
        if(a[i]%i!=0) {
            go(1,i,i-(a[i]%i));
        }
        go(i,1,a[i]/i);
    }
    for(int i=2;i<=n;++i) {
        go(1,i,musthave);
    }
    cout << ans.size()<< endl;
    for(auto u: ans) {
        cout << u[0] << ' ' << u[1] << ' ' << u[2] << endl;
    }

}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}