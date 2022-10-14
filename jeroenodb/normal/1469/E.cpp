#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e6+1;
bitset<(1<<20) + 5> can;
int main() {
    int t; cin >> t;

    while(t--) {
        int n,k; cin >> n >> k;

        can.set();
        string s; cin >> s;
        int cur = 0;
        int bs = min(k,20);
        int mask = (1<<bs)-1;
        vector<int> pref(n+1);
        for(int i=0;i<n;++i) {
            pref[i+1] = pref[i]+ (s[i]=='0' );
        }
        for(int i=k-bs;i<k;++i) {
            cur<<=1;
            cur&= mask;
            cur+= s[i]=='0';
        }
        if(pref[k-bs]==0) can[cur] = false;
        for(int i=k;i<n;++i) {
            cur<<=1;
            cur&= mask;
            cur+= s[i]=='0';
            if(pref[i+1-bs]-pref[i-k+1]==0) can[cur] = false;
        }
        int best = can._Find_first();
        if(best==(1<<bs)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            string ans(k-bs,'0');
            for(int i=bs-1;i>=0;--i) {
                ans.push_back(((1<<i) & best)?'1':'0');
            }
            cout << ans << endl;
        }
        
    }
}