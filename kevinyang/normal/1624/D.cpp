#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int>freq(26);
        for(int i = 0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int odd = 0;
        for(int i = 0; i<26; i++){
            if(freq[i]%2==1){
                odd++;
                freq[i]--;
            }
        }
        int v = 0;
        for(int i = 0; i<26; i++){
            v+=freq[i];
        }
        v/=2;
        int ans = 0;
        ans+=v/k*2;
        v%=k;
        odd+=v*2;
        if(odd>=k){
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}