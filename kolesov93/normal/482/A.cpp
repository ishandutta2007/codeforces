#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

bool u[1110011];

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        for (int i = 1; i <= n; ++i) printf("%d ", i);
        cout << endl;
        return 0;
    }

    vector<int> a;
    a.push_back(0);
    for (int i = 1; i <= k; ++i) {
        if (i & 1) {
            a.push_back(a.back() + i);
        } else {
            a.push_back(a.back() - i);
        }
    }
    int mx = a[0];
    for (int i = 0; i < a.size(); ++i) mx = max(mx, a[i]);
    int shift = n - mx;

    for (int i = 0; i < a.size(); ++i) {
        a[i] += shift;
        u[ a[i] ] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (!u[i]) printf("%d ", i);
    for (int i = 0; i < a.size(); ++i) printf("%d ", a[i]);
    cout << endl;

    return 0;
}