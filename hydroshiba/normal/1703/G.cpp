#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    
    lol cur = 0;
    lol ans = 0;
    
    for(int i = -1; i < n; ++i){
        lol bad = 0;
        if(i > -1) cur += arr[i] - k;
        
        for(int j = 1; j <= 30; ++j){
            if(i + j == n) break;
            bad += (arr[i + j] >> j);
        }
        
        ans = max(ans, cur + bad);
    }
    
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}