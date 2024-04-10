#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<long long> plus(m, 0), minus(m, 0);
    for (int i = 0; i < m; i++) {
        long long many = n / m;
        if (i != 0 && (n % m) >= i)
            many++;
        int x = (long long)i*i%m;
        plus[x] += many;
    }

    long long result = 0;
    for (int i = 0; i < m; i++) {
        result += plus[i] * plus[(m - i) % m];
    }
    cout << result << '\n';
}