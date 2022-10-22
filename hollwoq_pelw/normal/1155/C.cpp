#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    long long x[n], g = -1, q;
    for (int i = 0; i < n; i++){
        cin >> x[i];
        if (i > 1) g = __gcd(x[i]-x[i-1], g);
        else if (i) g = x[i]-x[i-1];
    }
    for (int i = 1; i <= m; i++){
        cin >> q;
        if (g%q==0) {cout << "YES\n" << x[0] << ' ' << i; return 0;}
    }
    cout << "NO";
    return 0;
}