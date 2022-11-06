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
        if(n==1){
            cout << s << s << "\n";
            continue;
        }
        if(s[0]==s[1]){
                cout << s[0] << s[0] << "\n";
                continue;
            }
        int idx = -1;
        for(int i = 0; i<n-1; i++){
            if(s[i]<s[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            if(s[0]==s[1]){
                cout << s[0] << s[0] << "\n";
                continue;
            }
            else{
                cout << s;
                reverse(s.begin(),s.end());
                cout << s << "\n";
            }
        }
        else{
            for(int i = 0; i<=idx; i++){
                cout << s[i];
            }
            for(int i = idx; i>=0; i--){
                cout << s[i];
            }
            cout << "\n";
        }
    }
    return 0;
}