#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    if(a < b) swap(a, b);
    if(k > 60){
        cout << "NO\n";
        return;
    }
    if(k == 1){
        if(a%b == 0 && a > b) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    /*if(a%b == 0){
        int x = a/b;
        int primes = 0;
        for(int i=2; i*i<=x; i++){

        }
        if(primes >= k){
            cout << "YES\n";
            return;
        }
    }*/
    int primes = 0;
    for(int i=2; i*i<=a; i++){
        while(a%i == 0){
            a /= i;
            primes++;
            if(primes >= k){
                cout << "YES\n";
                return;
            }
        }
    }
    if(a > 1) primes++;
    for(int i=2; i*i<=b; i++){
        while(b%i == 0){
            b /= i;
            primes++;
            if(primes >= k){
                cout << "YES\n";
                return;
            }
        }
    }
    if(b > 1) primes++;
    if(primes >= k){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}