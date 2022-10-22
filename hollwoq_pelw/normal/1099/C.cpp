#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n, t = 0;
    cin >> s >> n;
    for (int i = 0; i < s.length(); i++){
        if (s[i] != '?' && s[i] != '*'){
            n --;
        }
    }
    //cout << n << endl;
    string r = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] != '?' && s[i] != '*'){
            r += s[i];
        }else{
            while (n > 0 && s[i] == '*') {r += s[i-1]; n--;}
            
            if (n < 0) {r = r.substr(0, r.length()-1); n++;}
            //cout << n << endl;
        }
    }
    if (n == 0) cout << r;
    else cout << "Impossible";
    return 0;
}