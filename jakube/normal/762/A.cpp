#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, k;
    cin >> n >> k;
    
    vector<long long> d;
    for (long long div = 1; div*div <= n; div++) {
        if (n % div == 0) {
            d.push_back(div);
            if (div * div != n)
                d.push_back(n / div);
        }
    }
    sort(d.begin(), d.end());
    
    if (k > d.size()) cout << -1 << endl;
    else cout << d[k - 1] << endl;


    return 0;
}