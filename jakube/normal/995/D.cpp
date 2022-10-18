#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(9);

    int n, r;
    cin >> n >> r;
    vector<int> v(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> v[i];
    }
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    cout << sum / (double)(1 << n) << '\n';
    for (int i = 0; i < r; i++) {
        int p, x;
        cin >> p >> x;
        sum -= v[p];
        v[p] = x;
        sum += v[p];
        cout << sum / (double)(1 << n) << '\n';
    }
}