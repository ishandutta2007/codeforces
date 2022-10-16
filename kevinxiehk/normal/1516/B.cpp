#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int xs = 0;
    for(int i = 0; i < n; i++) xs ^= arr[i];
    if(xs == 0) {
        if(n > 1) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    int xxs = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        xxs ^= arr[i];
        if(xxs == xs) {
            cnt++;
            xxs = 0;
        }
    }
    if(cnt >= 3) cout << "YES\n";
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