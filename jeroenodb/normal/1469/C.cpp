#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;

int main() {
    int t; cin >> t;
    while(t--) {
        int n,k,h0; cin >> n >> k;
        cin >> h0;
        int lo = h0, hi = h0;
        bool impos = false;
        int cur; 
        for(int i=0;i<n-1;++i) {
            cin >> cur;
            hi = min(hi+k-1, cur+k-1);
            lo = max(lo-k+1, cur);
            if(lo>hi) impos = true;
        }
        if(impos or lo > cur) cout << "no\n";
        else cout << "yes\n";

    }
}