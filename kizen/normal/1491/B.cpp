#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, u, v;
        cin >> n >> u >> v;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int ans = (int)2e9 + 7;
        for(int i = 1; i < n; ++i){
            if(abs(a[i] - a[i - 1]) >= 2){
                ans = 0;
            }
            else if(abs(a[i] - a[i - 1]) == 1){
                ans = min({ans, u, v});
            }
            else{
                ans = min(ans, v + min(u, v));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}