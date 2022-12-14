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
        int n; cin >> n;
        string s; cin >> s;
        if(n % 2 == 0){
            int l = n / 2 - 1, r = n / 2;
            while(l > 0){
                if(s[l - 1] == s[l] && s[r + 1] == s[r]){
                    --l, ++r;
                }
                else{
                    break;
                }
            }
            cout << r - l + 1 << '\n';
        }
        else{
            int l = n / 2, r = n / 2;
            while(l > 0){
                if(s[l - 1] == s[l] && s[r + 1] == s[r]){
                    --l, ++r;
                }
                else{
                    break;
                }
            }
            cout << r - l + 1 << '\n';
        }
    }
    return 0;
}