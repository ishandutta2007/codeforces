#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];
        set<int> s;
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                s.insert(a[j]-a[i]);
            }
        }
        cout << s.size() << endl;
    }
}