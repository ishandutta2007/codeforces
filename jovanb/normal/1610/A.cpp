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
        int a, b;
        cin >> a >> b;
        if(a == 1 && b == 1) cout << "0\n";
        else if(min(a, b) == 1) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}