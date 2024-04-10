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
        int a, b, c;
        cin >> a >> b >> c;
        cout << (a + c)%2 << "\n";
    }
    return 0;
}