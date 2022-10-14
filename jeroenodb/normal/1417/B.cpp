#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int mxN = 1e5+1;
void solve() {
    int n,T; cin >> n >> T;
    int a[mxN];
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    unordered_map<int,int> c,d;
    bool ans[mxN] = {};
    for(int i=0;i<n;++i) {
        auto iter = c.find(T-a[i]);
        if(iter==c.end()) {
            c[a[i]]++;
            ans[i] = true;
            continue;
        }
        auto iter2 = d.find(T-a[i]);
        if(iter2==d.end()) {
            d[a[i]]++;
            continue;
        }
        if(iter->second < iter2->second) {
            c[a[i]]++;
            ans[i]=true;
        } else {
            d[a[i]]++;
        }
    }
    for(int i=0;i<n;++i) {
        cout << ans[i] << ' ';
    } cout << endl;



}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}