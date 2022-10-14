#pragma GCC optimize "Ofast"
#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;
const long long MOD = 1e9 + 11, x = 1e8+1234567;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        int ans = 0;
        for(int i=1;i<n;++i) {
            if(i>1) {
                if(s[i]==s[i-2]) {
                    s[i] = '#';
                    ans++;
                    continue;
                }
            } 
            if(s[i]==s[i-1]) {
                s[i] = '#';
                ans++;
            }
        }
        cout << ans << endl;
    }
}