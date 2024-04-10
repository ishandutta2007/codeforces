#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(9);

    long long k, d, t;
    cin >> k >> d >> t;
    
    if (k % d == 0) {
        cout << t << endl;
        return 0;
    }

    // one pass
    long long dur_t = k + (d - k % d);
    double dur_cook = k + (d - k % d) / (double)2;

    auto passes = floor(t / dur_cook);
    double result = passes * dur_t;
    double rem = t - passes * dur_cook;
    if (rem <= k) {
        cout << result + rem << endl;
    } else {
        cout << result + k + (rem - k) * 2 << endl;
    }
}