#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0;i < n;i++){
        if(i < n - 1){
            if(s[i] != s[i + 1]){
                ans +=  s[i];
                ans += s[i + 1];
                i += 1;
            }
        }
    }
    cout << n - ans.size() << endl;
    cout << ans;
}