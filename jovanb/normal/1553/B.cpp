#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = s.size();
    for(int i=0; i<n; i++){
        string cr = "";
        for(int j=i; j<n; j++){
            cr += s[j];
            string cc = cr;
            if(cc == t){
                cout << "YES\n";
                return;
            }
            for(int k=j-1; k>=0; k--){
                cc += s[k];
                if(cc.size() > t.size()) break;
                if(cc == t){
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
aaa
aaaaa
*/