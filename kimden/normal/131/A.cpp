#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool invert = true;
    for(int i=1;i<s.length();i++){
        if(s[i]>='a'){
            invert = false;
            break;
        }
    }
    if(invert){
        if(s[0]>='a'){
            cout << (char)(s[0]+'A'-'a');
        }else{
            cout << (char)(s[0]+'a'-'A');
        }
        for(int i=1;i<s.length();i++){
            cout << (char)(s[i]+'a'-'A');
        }
    }else{
        cout << s;
    }
}