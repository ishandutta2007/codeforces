#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    string s;
    cin >> s;
    string forbid = "aoyeui";
    for(int i = 0; i < s.size(); i++){
        bool ok = true;
        char c = s[i];
        if(isupper(c)) c = c - 'A' + 'a';
        REP(j, forbid.size()){
            if(c == forbid[j]) ok = false;
        }
        if(ok){
            cout << "." << c;
        }
    }
    cout << endl;
    return 0;
}