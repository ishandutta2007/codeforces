#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int x) {
    cout << "! " << x << endl;
}

vector<int> primes = {2, 3, 7, 11, 13, 17, 19, 23, 29};

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<int> rems(9);
        ll prod = 1293938646;
        for(int i = 1; i < 30; i++) {
            ll x = ask(i, prod + i);
            for(int j = 0; j < 9; j++) {
                if(!(x % primes[j])) {
                    rems[j] = (primes[j] - (i % primes[j])) % primes[j];
                }
            }
        }
        prod = 1;
        ll ans = 0;
        for(int i = 0; i < 9; i++) {
            while(ans % primes[i] != rems[i]) ans += prod;
            prod *= primes[i];
        }
        answer(ans);
    }
}