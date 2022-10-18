#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    vector<int> psum(n+1, 0);
    for (int i = 0; i < n; i++) {
        psum[i+1] = psum[i] + v[i];
    }

    int total = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        
        int s = psum[r] - psum[l-1];
        if (s > 0)
            total += s;
    }

    cout << total << endl;

    return 0;
}