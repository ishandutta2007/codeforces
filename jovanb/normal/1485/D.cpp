#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    int lcm = 1;
    for(int i=1; i<=16; i++){
        lcm = lcm*i/__gcd(lcm, i);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin >> x;
            if((i+j)%2) cout << lcm << " ";
            else cout << lcm + x*x*x*x << " ";
        }
        cout << "\n";
    }
    return 0;
}