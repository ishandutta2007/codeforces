#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    bool nbrok[26] = {0};
    int c = 0;
    s += '!';
    for(int i = 0; i < s.length(); i++){
        if (i == 0 || s[i] == s[i-1]){
            c ++;
        }else{
            if (c%2){
                nbrok[s[i-1]-'a'] = true;
            }
            c = 1;
        }
    }
    for (int i = 0; i < 26; i++){
        if (nbrok[i]) cout << (char)('a'+i);
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}