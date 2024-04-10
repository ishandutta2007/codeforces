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
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];
        int i=1, prev=0, tmp = 1;
        int ans = 0;
        while(i<n) {
            while(i<n and a[i]==a[prev]) {
                tmp++;
                ++i;
            }
            if(i==n) break;
            if(tmp>=2) {
                ans++;
                if(a[i]==a[prev]+1) {
                    tmp=1;
                } else {
                    ans++;
                    tmp=0;
                }
            } else {
                ans++;
                tmp=0;
            }
            prev = i;
        }
        if(tmp>=2) ans+=2;
        else if(tmp==1) ans++;
        cout << ans << endl;
    }
}