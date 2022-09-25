#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        vector<LL> a(n + 2);
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        LL ans = 0;
        for(int i = 1; i <= n; i += 1){
            LL h = max(min(a[i] - a[i - 1] , a[i] - a[i + 1]), 0LL);
            ans += h;
            a[i] -= h;
        }
        for(int i = 0; i <= n; i += 1) ans += abs(a[i] - a[i + 1]);
        cout << ans << "\n";
    }
    return 0;
}