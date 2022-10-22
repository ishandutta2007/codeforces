#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int p[n], ans[n];
    bool nvisit[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i]; 
        p[i]--;
        nvisit[i] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!nvisit[i]) continue;
        int cur = p[i], d = 1;
        vector<int> loops;
        loops.push_back(i);
        while(cur != i){
            loops.push_back(cur);
            nvisit[cur] = false;
            cur = p[cur];
            d ++;
        }
        for (auto id:loops) ans[id] = d;
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}