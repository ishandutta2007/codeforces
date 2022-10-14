#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin >> n;
        int ans = 0,dist=0;
        bool seen=false;
        for(int i=0;i<n;++i) {
            int cur; cin >> cur;
            if(cur==1) {
                ans+=dist;
                dist=0;
                seen = 1;
            } else {
                dist+=seen;
            }
        }
        cout << ans << endl;
        
    }
}