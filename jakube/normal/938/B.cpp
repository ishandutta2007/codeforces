#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n + 2);
    v[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i+1];
    }
    v[n+1] = 1'000'000;
    
    int m = std::numeric_limits<int>::max();
    for (int i = 0; i <= n; i++) {
        m = min(m, max(v[i] - v.front(), + v.back() - v[i+1]));
    }
    cout << m << endl;
}