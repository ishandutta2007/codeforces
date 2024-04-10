#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,r,p,s;
    cin >> n >> r >> p >> s;
    int c = 0;
    string a = "",b;
    cin >> b;
    for (int i = 0; i < n; i ++){
        if (b[i] == 'R'){
            if (p > 0){ p --; a += 'P'; c++;}
            else {a += '!';} 
        }if (b[i] == 'P'){
            if (s > 0){ s --; a += 'S'; c++;}
            else {a += '!';} 
        }if (b[i] == 'S'){
            if (r > 0){ r --; a += 'R'; c++;}
            else {a += '!';} 
        }
    }
    if (2*c < n){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
        if (a[i] == '!'){
            if (r > 0){cout << 'R'; r--;}
            else if (p > 0){cout << 'P'; p--;}
            else if (s > 0){cout << 'S'; s--;}
        }else{
            cout << a[i];
        }
    }
    cout << endl;
}
int main(){
    int q; cin >> q;
    while(q--) solve();
    return 0;
}