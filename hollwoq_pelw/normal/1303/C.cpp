#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    string res = "";
    int i = -1;
    for (char c:s){
        if (res.length() <= 1) {
            res += c;
            i ++;
        }else{
            if (res.length() > 26) {cout << "NO" << endl; return;}
            if (res.find(c) != std::string::npos){
                if (i == 0){
                    if (c != res[i+1]) {cout << "NO" << endl; return;}
                }
                else if (i == res.length()-1){
                    if (c != res[i-1]) {cout << "NO" << endl; return;}
                }
                else if (c != res[i-1] && c != res[i+1]) {cout << "NO" << endl; return;}
                
            }
            if (i == 0 && c != res[i+1]){
                res = c+res;
            }
            else if (i == res.length()-1 && c != res[i-1]) {
                res += c; 
                i++;
            }
            else{
                if (c == res[i+1]) i++;
                else if (c == res[i-1]) i--;
                else {cout << "NO" << endl; return;}
            }
        }
    }
    cout << "YES" << endl << res;
    for (int i = 0; i < 26; i++){
        char k = i + 'a';
        if (res.find(k) == std::string::npos) cout << k;
    }
    cout << endl;
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