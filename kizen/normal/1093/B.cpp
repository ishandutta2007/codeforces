#include <bits/stdc++.h>

using namespace std;

int T;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> s;
        sort(s.begin(), s.end());
        if(s[0]==s[(int)s.size()-1]) cout << "-1" << "\n";
        else cout << s << "\n";
    }
    return 0;
}