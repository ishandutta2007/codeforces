
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int r, b, d;
    cin >> r >> b >> d;
    if(d == 0) {
        cout << (r == b ? "YES\n" : "NO\n");
        return;
    }
    if((abs(r - b) / d) + (abs(r - b) % d != 0) > min(r, b)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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