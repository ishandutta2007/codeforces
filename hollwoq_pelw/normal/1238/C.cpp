#include <bits/stdc++.h>
using namespace std;
void solve(){
    int h,n;
    cin >> h >> n;
    int p[n+1];
    for (int i = 0; i < n; i++) cin >> p[i];
    p[n] = 0;
    int ans = 0;
    for (int i = 1; i < n; i++){
        if (p[i]-1 > p[i+1]) ans++;
        else i ++;
    }
    cout << ans << endl;
    
}
int main(){
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}