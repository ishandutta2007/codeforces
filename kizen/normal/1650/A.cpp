#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        char c; cin >> c;
        int ans = 0;
        int n = (int)s.size();
        for(int i = 0; i < n; i += 2){
            ans |= (s[i] == c);
        }
        for(int i = n - 1; i >= 0; i -= 2){
            ans |= (s[i] == c);
        }
        if(n % 2 == 0) ans = 0;
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}