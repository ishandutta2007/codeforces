#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, M, D;
    cin >> n >> k >> M >> D;
    
    auto f = [n,k](long long x){
        return x + (n - x) / x / k * x;
    };

    long long best = 0;
    for (int R = 1; R <= D; R++) {
        if (n / k < (R - 1))
            continue;
        long long x = n / ((R - 1) * k + 1);
        x = min(x, M);
        if (x && f(x) / x == R)
            best = max(best, f(x));
    }

    // long long L = 0; // too slow
    // long long R = n; // not to slow
    // while (L + 1 < R) {
    //     long long M = (L + R) / 2;
    //     if (f(M) / M <= D)
    //         R = M;
    //     else
    //         L = M;
    // }

    // L = R;
    // R = M;
    // long long best = max(f(L), f(R));

    // while (L + 1 < R) {
    //     long long M = (L + R) / 2;
    //     if (f(M) < f(M+1)) {
            
    //     }

    // }




    cout << best << '\n';
    
}