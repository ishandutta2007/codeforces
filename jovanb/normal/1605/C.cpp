#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s.find("aa") != string::npos) cout << "2\n";
        else if(s.find("aca") != string::npos || s.find("aba") != string::npos) cout << "3\n";
        else if(s.find("abca") != string::npos || s.find("acba") != string::npos) cout << "4\n";
        else if(s.find("abbacca") != string::npos || s.find("accabba") != string::npos) cout << "7\n";
        else cout << "-1\n";
    }
    return 0;
}