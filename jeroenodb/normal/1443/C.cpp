#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 2e5+2;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<long long,long long>> ab(n+2);
        for(int i=0;i<n;++i) {
            cin >> ab[i+1].first;
        } 
        for(int i=0;i<n;++i) {
            cin >> ab[i+1].second;
            ab[i+1].second*=-1;
        }
        sort(ab.begin()+1,ab.end()-1);
        long long ans=ab[n].first;
        for(int i=n;i>=1;--i) {
            ab[i].second+=ab[i+1].second;
            ans = min(ans,max(ab[i-1].first,-ab[i].second)); 
        }
        cout << ans << endl;

    }
    
}