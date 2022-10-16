#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second   
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, t;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
    }
    if(sum == n) cout << "0\n";
    else if(sum < n) cout << "1\n";
    else cout << sum - n << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();

    return 0;
}