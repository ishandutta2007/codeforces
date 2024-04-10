#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        string s;
        cin >> s;
        bool p = false;
        for (int i = 0; i < s.length()-1; i++){
            //cout << s << ' ';
            if (s[i] == '?'){
                if (i == 0) {
                    if (s[i+1] != 'a') s[i] = 'a';
                    else s[i] = 'b';
                }
                else {
                    if (s[i-1] != 'a' && s[i+1] != 'a') s[i] = 'a';
                    else if (s[i-1] != 'b' && s[i+1] != 'b') s[i] = 'b';
                    else s[i] = 'c';
                }
            }else {
                if (s[i] == s[i+1]){ 
                    cout << -1 << endl;
                    p = true;
                    break;
                }
            }
        }
        if (s[s.length()-1] == '?'){
            if (s[s.length()-2] == 'a'){
                s[s.length()-1] = 'b';
            }else {
                s[s.length()-1] = 'a';
            }
        }
        if (p) continue;
        cout << s << endl;
    }
    return 0;
}