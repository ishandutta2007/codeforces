#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <string>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;

int main() {
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vector<int> x(n),y(n);
        for(int i=0;i<n;++i) cin >> x[i] >> y[i];
        bool found = false;
        for(int i=0;i<n;++i) {
            int tmp = 0;
            for(int j=0;j<n;++j) {
                tmp = max(tmp,abs(x[i]-x[j])+abs(y[i]-y[j]));
            }
            if(tmp<=k) {
                cout << "1\n";
                found = true;
                break;
            }
        }
        if(!found) cout << "-1\n";
        

    }
}