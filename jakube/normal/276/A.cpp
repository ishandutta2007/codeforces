#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    
    int m = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        int f, t;
        cin >> f >> t;
        if (k < t)
            m = max(f - t + k, m);
        else
            m = max(f, m);
    }

    cout << m << endl;

    return 0;
}