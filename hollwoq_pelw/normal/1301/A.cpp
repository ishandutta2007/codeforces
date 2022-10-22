#include <bits/stdc++.h>
using namespace std;
void solve(){
    string a,b,c;
    cin >>a >> b >> c;
    for (int i = 0; i < a.length();i++){
        if (!(a[i]==c[i] || b[i]==c[i])){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
}
int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
}