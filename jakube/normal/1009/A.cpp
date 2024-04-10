#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int& x : c)
        cin >> x;
    vector<int> a(m);
    for (int& x : a)
        cin >> x;
    
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && a[j] >= c[i]) {
            cnt++;
            j++;
        }
    }
    cout << cnt << '\n';
}