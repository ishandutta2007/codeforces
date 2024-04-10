#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll PRIME = 998244353;

ll expo(ll a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    int k = n / 2;
    ll e = expo(a, k);
    if (n % 2 == 0) return (e * e) % PRIME;
    e = (e * e) % PRIME;
    return (a * e) % PRIME;
}

ll inverse(ll a) {
    return expo(a, PRIME - 2);
}

int main(void) {
    ll n, k;
    cin >> n >> k;
    if (k > n) {
        cout << "0\n";
        return 0;
    }
    vector<ll> combi(n);
    for (int i = 0; i < k - 1; i++) combi[i] = 0;
    combi[k - 1] = 1;
    for (int i = k; i <= n - 1; i++) {
        combi[i] = (combi[i - 1] * i) % PRIME;
        combi[i] = (combi[i] * inverse(i - k + 1)) % PRIME;
    }

    ll count = 0;
    for (int d = 1; d <= n; d++) {
        count = (count + combi[n / d - 1]) % PRIME;
    }

    cout << count << "\n";

}