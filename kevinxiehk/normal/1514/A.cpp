#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, t ;
    cin >> n;
    int yes = true;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(floor(sqrt(t)) * floor(sqrt(t)) != t) yes = false;
    }
    cout << (yes ? "NO\n" : "YES\n");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}