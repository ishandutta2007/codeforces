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
        string s2;
        cin >> s2;
        if(s==s2){
            cout << "0\n";
            continue;
        }
        if(count(s.begin(),s.end(),'1')==0){
            cout << "-1\n";
            continue;
        }
        
        int aa = 0;
        int ab = 0;
        int ba = 0;
        int bb = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='0'&&s2[i]=='0')aa++;
            if(s[i]=='0'&&s2[i]=='1')ab++;
            if(s[i]=='1'&&s2[i]=='0')ba++;
            if(s[i]=='1'&&s2[i]=='1')bb++;
        }
        int ans = (int)1e9;
        if(bb==aa+1){
            ans = min(ans,bb+aa);
        }
        if(ab==ba){
            assert(ab>0);
            assert(ba>0);
            ans = min(ans,ab+ba);
        }
        if(ans>n){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
    return 0;
}