#include <bits/stdc++.h>
using namespace std;

bool isvow(char a){
    return (a == 'a' || a == 'e' || a == 'u' || a == 'i' || a == 'o');
}

int main(){
    string s,t;
    cin >> s >> t;
    if (s.length() != t.length()) return cout << "NO", 0;
    for (int i = 0; i < s.length(); i++){
        if (!(isvow(s[i]) == isvow(t[i]))) return cout << "NO", 0;
    }
    return cout << "YES", 0;
    
}