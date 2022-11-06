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
        vector<int>freq(26);
        for(int i = 0; i<26; i++){
            freq[i] = count(s.begin(),s.end(),(char)('a'+i));
        }
        bool f = true;
        if(freq[0]!=1)f = false;
        for(int i = 0; i<25; i++){
            if(freq[i]<freq[i+1])f = false;
        }
        if(!f){
            cout << "NO\n";
            continue;
        }
        int start = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='a'){
                start = i;
                break;
            }
        }
        int l = start; int r = start;
        for(int i = 1; i<n; i++){
            int idx = 0;
            for(int j = 0; j<n; j++){
                if(s[j]==(char)('a'+i)){
                    idx = j;
                    break;
                }
            }
            if(idx==l-1){
                l--;
            }
            else if(idx==r+1){
                r++;
            }
            else{
                f = false;
            }
        }
        if(f)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}