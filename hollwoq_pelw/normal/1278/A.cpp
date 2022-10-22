#include <bits/stdc++.h>
using namespace std;
bool isSuffle(string a, string b){
    int coDif[26] = {0};
    for (int i = 0; i < a.length(); i++){
        coDif[a[i]-'a'] ++;
        coDif[b[i]-'a'] --;
    }
    for (int i = 0; i < 26; i++) {
        if (coDif[i] != 0) return false;
    }
    return true;
}
void solve(){
    string s,h;
    cin >> s >> h;
    if (h.length() < s.length()){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < h.length()-s.length()+1; i++){
        string t = h.substr(i,s.length());
        if (isSuffle(t,s)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
    
}
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        solve();
    }
    return 0;
    
}