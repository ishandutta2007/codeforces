#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    vector<string> names = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    int hoge;
    cin >> hoge;
    string s;
    cin >> s;
    for(string t : names) {
        if(s.size() == t.size()) {
            bool ok = true;
            REP(i, s.size()){
                if(s[i] != t[i] && s[i] != '.') {
                    ok = false;
                }
            }
            if(ok) {
                cout << t << endl;
            }
        }
    }
    return 0;
}