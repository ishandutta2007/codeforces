#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mxN = 3e5+1;
int a[mxN];
bool comp(int c, int d) {
    if(a[c]==a[d]) return c < d;
    return a[c] < a[d];
}
int mindist(vector<int>& l) {
    int mx = 0;
    for(int i=1;i<l.size();++i) {
        mx = max(mx,l[i]-l[i-1]);
    }
    return mx;

}
void solve() {
    int n;
    
    cin >> n;
    vector<int> order(n);
    for(int i=0;i<n;++i) {
        order[i]=i;
        cin >> a[i];
    }
    sort(order.begin(),order.end(),comp);
    vector<int> ks = {-1};
    ks.push_back(order[0]);
    vector<int> ans(n+4);
    for(int i=1;i<=n;++i) ans[i] = -1;
    int best = n+1;
    for(int i=1;i<n;++i) {
        if(a[order[i]] != a[order[i-1]]) {
            ks.push_back(n);
            int mink = mindist(ks);
            for(int j=mink;j<best;++j) {
                ans[j]=a[order[i-1]];
            }
            best = min(mink,best);
            ks = {-1,order[i]};
        } else {
            ks.push_back(order[i]);
        }
    }
    ks.push_back(n);
    int mink = mindist(ks);
    for(int j=mink;j<best;++j) {
        ans[j]=a[order[n-1]];
    }
    for(int i=1;i<=n;++i) {
        cout << ans[i] << ' ';
    } cout << endl;


}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}