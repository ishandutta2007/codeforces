#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> b(n);
    for (auto& x : b)
        cin >> x;
    
    double L = 0; // not possible
    double R = 2e9; // possible
    for (int i = 0; i < 200; i++) {
        double M = (L + R) / 2;

        double weight = m + M;
        for (int i = 0; i < n; i++) {
            weight -= weight / a[i];
            weight -= weight / b[(i+1)%n];
        }
        if (weight >= m)
            R = M;
        else
            L = M;
    }
    if (R == 2e9)
        cout << -1 << endl;
    else {
        std::cout << std::fixed << std::setprecision(10);
        cout << R << '\n';
    }
}