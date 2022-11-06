#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        char prev = '1';
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='0'){
                if(prev=='1')ans++;
            }
            prev = s[i];
        }
        cout << min(ans,2LL) << "\n";
    }
    return 0;
}