#include <bits/stdc++.h>
using namespace std;

bool coprime(int a, int b) {
    while (a != 0 && b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a+b > 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<int> dp(n, 0);
    vector<int> d(1e5+1, 0);

    if (n == 1 && v[0] == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int m = 0;
        for (int div = 2; div*div <= v[i]; div++) {
            if (v[i] % div == 0) {
                m = max(m, d[div] + 1);
                m = max(m, d[v[i]/div] + 1);
            }
        }
        m = max(m, d[v[i]] + 1);
        dp[i] = m;
        for (int div = 2; div*div <= v[i]; div++) {
            if (v[i] % div == 0) {
                d[div] = max(d[div], m);
                d[v[i]/div] = max(d[v[i]/div], m);
            }
        }
        d[v[i]] = max(m, d[v[i]]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;



    return 0;
}