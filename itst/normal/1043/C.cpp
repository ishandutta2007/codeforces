#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;

int main(){
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; ++i)
        if(s[i] == 'a' && (s.size() - 1 == i || s[i + 1] == 'b'))
            cout << 1 << ' ';
        else
            if(s[i] == 'b' && (s.size() - 1 != i && s[i + 1] == 'a'))
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
    return 0;
}