#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool isPrime(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        if(!(n%i)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        ll s = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            s += v[i];
        }
        if(!isPrime(s)) {
            cout << n << '\n';
            for(int i = 0; i < n; i++) cout << i+1 << ' ';
            cout << '\n';
        }
        else {
            for(int i = 0; i < n; i++) {
                if(!isPrime(s - v[i])) {
                    cout << n-1 << '\n';
                    for(int j = 0; j < n; j++) if(j != i) cout << j+1 << ' ';
                    cout << '\n';
                    break;
                }
            }
        }
    }
}