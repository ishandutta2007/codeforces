#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int a, b, c; cin >> a >> b >> c;
        cout << a+b+c - min({a,b,c}) - max({a,b,c}) << '\n';
    }
}