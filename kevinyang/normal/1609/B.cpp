#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "dddddd" + s + "dddddd";
    int ans = 0;
    for(int i = 4; i<n+7; i++){
        if(s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a'){
            ans++;
        }
    }
    while(q--){
        int idx;
        cin >> idx;
        char ch;
        cin >> ch;
        for(int i = idx+5; i<=idx+7; i++){
            if(s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a'){
                ans--;
            }
        }
        s[idx+5] = ch;
        for(int i = idx+5; i<=idx+7; i++){
            if(s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a'){
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}