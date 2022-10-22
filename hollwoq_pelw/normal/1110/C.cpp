#include <bits/stdc++.h>
using namespace std;

void solve(){
    long n, p = 1;
    cin >> n;
    while(p <= n) p*=2;
    if (p-1 > n) {cout << p - 1 << endl; return;}
    for (int i = 3; i <= n; i++){
        if (i*i > n) i = n;
        if (n%i==0){cout << n/i << endl; return;}
    }
}

int main(){
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}