#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    string s;
    while(cin >> s){
        string ref = "AHIMOTUVWXY";
        set<char> refs;
        for(char c : ref) refs.insert(c);
        bool ok = true;
        REP(i, s.size()){
            if(refs.count(s[i])){
            }else{
                ok = false;
            }
        }
        string t = s;
        reverse(t.begin(), t.end());
        if(s != t) ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}