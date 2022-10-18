#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    int R = n; // possible
    int L = -1; // impossible
    while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> v(m, k);
        bool possible = true;
        int j = 0;
        for (int i = M; i < n; i++) {
            int x = a[i];
            while (j < m && v[j] < x) {
                j++;
            }
            if (j == m)
                possible = false;
            else
                v[j] -= x;
        }
        if (possible)
            R = M;
        else
            L = M;
    }
    cout << n - R << endl;
    
}