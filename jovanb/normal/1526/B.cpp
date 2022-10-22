#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool solve(){
    int tries = 11;
    int x;
    cin >> x;
    while(tries--){
        if(x%11 == 0) return 1;
        x -= 111;
        if(x < 0) return 0;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}