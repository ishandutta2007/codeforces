#include <bits/stdc++.h>
using namespace std;

long long solve(long long n){
    long long nok = 1;
    long long ans = 0;
    for (int x = 2; x < 400; ++x){
        long long nok1 = (nok * x) / gcd(x, nok);
        if (nok > n) {
            break;
        }
        long long d = nok1 / nok;
        long long b = n / nok;
        ans += x * (b - b / d);
        ans %= 1000000007;
        nok = nok1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}