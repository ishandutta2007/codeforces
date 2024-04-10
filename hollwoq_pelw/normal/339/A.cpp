#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1') {s1++;}
        if (s[i] == '2') {s2++;}
        if (s[i] == '3') {s3++;}
    }
    
    while (s1){
        s1 --;
        cout << 1;
        if (s1 + s2 + s3) cout << '+';    
        
    }
    while (s2){
        s2 --;
        cout << 2;
        if (s1 + s2 + s3) cout << '+';    
        
    }
    while (s3){
        s3 --;
        cout << 3;
        if (s1 + s2 + s3) cout << '+';    
        
    }

    return 0;
}