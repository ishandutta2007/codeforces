#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        int ans = 0;
        vector<bool>good(n);
        for(int i = 0; i<n; i++){
            if(s[i]=='0'&&t[i]=='0'){
                good[i] = true;
            }
        }
        for(int i = 0; i<n; i++){
            if(s[i]!=t[i]){
                ans+=2;
            }
            else if(s[i]=='0'&&t[i]=='0'){
                ans++;
            }
            else{
                bool f = false;
                if(i>0){
                    if(good[i-1]){
                        f = true;
                    }
                }
                if(i<n-1&&!f){
                    if(good[i+1]){
                        good[i+1] = false;
                        f = true;
                    }
                }
                
                ans+=f;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}