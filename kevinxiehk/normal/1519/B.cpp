#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if(k == x * y - 1) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    return 0;
}