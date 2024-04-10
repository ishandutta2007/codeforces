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
        int x;
        cin >> x;
        if(x%7 == 0){
            cout << x << "\n";
            continue;
        }
        int dost = 7 - x%7;
        if((x%10) + dost >= 10) x -= 7;
        cout << x + dost << "\n";
    }
    return 0;
}