#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n; 
    cin >> n;
    if(n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    n /= 2;
    int a = sqrt(n);
    if(a * a == n) {
        cout << "YES\n";
        return;
    }
    if(n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    n /= 2;
    a = sqrt(n);
    if(a * a == n) {
        cout << "YES\n";
        return;
    }
    while(n >= 2) {
        if(n % 2 == 1) {
            cout << "NO\n";
            return;
        }
        n /= 2;
    }
    cout << "YES\n";
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