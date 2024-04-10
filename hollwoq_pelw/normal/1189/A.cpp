#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int c = 0;
    for (char t:s){
        if (t-'0') c++;
        else c --;
    }
    if (c == 0){
        cout << 2 << endl << s[0] << ' ' << s.substr(1, s.length()-1);
    }else{
        cout << 1 << endl << s;
    }
    return 0;
}