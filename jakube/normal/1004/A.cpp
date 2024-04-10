#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    int cnt = 2;
    for (int i = 0; i + 1 < n; i++) {
        if (2 * d < x[i+1] - x[i])
            cnt += 2;
        if (2 * d == x[i+1] - x[i])
            cnt += 1;
    }
    cout << cnt << '\n';
}