#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, U;
    cin >> n >> U;
    vector<int> E(n);
    for (int i = 0; i < n; i++) {
        cin >> E[i];
    }
    
    int i = 0, j = 1, k = 1;
    double best = -1;
    for (; j <= n - 2; i++, j++) {
        while (k < n-1 && E[k+1] - E[i] <= U)
            k++;
        if (k > j) {
            best = max(best, (double)(E[k] - E[j]) / (double)(E[k] - E[i]));
        }
    }

    if (best < 0)
        cout << -1 << endl;
    else {
        std::cout << std::fixed << std::setprecision(9);
        cout << best << endl;
    }
}