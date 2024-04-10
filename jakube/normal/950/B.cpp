#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> y(m);
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    
    int sum_x = 0;
    int sum_y = 0;
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n || j < m) {
        if (sum_x <= sum_y)
            sum_x += x[i++];
        else
            sum_y += y[j++];
        if (sum_x == sum_y)
            cnt++;
    }
    cout << cnt << '\n';
}