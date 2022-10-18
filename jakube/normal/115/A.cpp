#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    int m = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        int c = 1;
        while (v[j] != -1) {
            c++;
            j = v[j] - 1;
        }
        m = max(m, c);
    }

    cout << m << endl;

    return 0;
}