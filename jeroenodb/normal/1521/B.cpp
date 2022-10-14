#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
const int prime = 1e9+7;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n); for(int& i: a) cin >> i;
        vector<array<int,4>> ans;
        for(int i=0;i+1<n;i+=2) {
            int x = min(a[i],a[i+1]);
            ans.push_back({i+1,i+2,x,prime});
        }
        cout << ans.size() << '\n';
        for(auto& move: ans) {
            for(auto i : move) {
                cout << i << ' ';
            } cout << '\n';
        }
    }
}