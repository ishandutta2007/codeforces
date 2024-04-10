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
        int n = s.size();
        bool f = false;
        for(int i = 0; i<n-1; i++){
            if((s[i]-'0')+s[i+1]-'0'>=10){
                f = true;
            }
        }
        if(f){
            int idx = 0;
            for(int i = n-2; i>=0; i--){
                if(s[i]-'0'+s[i+1]-'0'>=10){
                    idx = i;
                    break;
                }
            }
            int i = idx;
            cout << s.substr(0,idx);
            cout << (int)(s[i]-'0'+s[i+1]-'0');
            cout << s.substr(idx+2);
            cout << "\n";
        }
        else{
            int idx = 0;
            int i = idx;
            cout << s.substr(0,idx);
            cout << (int)(s[i]-'0'+s[i+1]-'0');
            cout << s.substr(idx+2);
            cout << "\n";
        }
    }
    return 0;
}