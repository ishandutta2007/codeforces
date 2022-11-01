#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    string s;
    cin >> s;
    if(islower(s[0])){
        s[0] = s[0] - 'a' + 'A';
    }
    cout << s << endl;
    return 0;
}