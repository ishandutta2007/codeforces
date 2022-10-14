#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 1e5;
void solve() {
    int n;
    long long w; cin >> n >> w;
    vector<long long> ws(n);
    long long sum =0, mn = 1e9;
    bool found = false; int ans;
    for(int i=0;i<n;++i) {
        cin >> ws[i];
        sum+=ws[i];
        mn = min(ws[i], mn);
        if((w+1)/2 <= ws[i] and  ws[i]<=w) {
            ans = i+1;
            found = true;
        }
    }
    if(found) {
        cout << "1\n" << ans << endl;
        return;
    }
    vector<int> order(n);
    for(int i=0;i<n;++i) order[i]=i;
    sort(order.begin(),order.end(), [&](int a, int b){return ws[a] < ws[b];});
    if(sum<(w+1)/2 or mn > w) {
        cout << "-1\n";
        return;
    }
    sum = 0;
    for(int i=0;i<n;++i) {
        int cur = ws[order[i]];
        if(cur > w/2) break;
        sum+=cur;
        if(sum>=(w+1)/2) {
            cout << i+1 << endl;
            for(int j=0;j<=i;++j) {
                cout << order[j]+1 << ' ';
            } cout << endl;
            return;
        }
    }
    cout << "-1\n";
}
int main() {
    int t; cin >> t;
    while(t--) {
        
        solve();
    }
}