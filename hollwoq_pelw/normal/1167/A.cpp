#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        bool f = 0;
        for (int i = 0; i <= n-11; i++){
            if (s[i] == '8') {f = 1; break;}
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}