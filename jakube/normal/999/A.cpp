#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int i = 0;
    int res = 0;
    for (; i < n && v[i] <= m; i++) {
        res++;
    }
    for (int j = n-1; j > i && v[j] <= m; j--)
        res++;
    cout << res << '\n';
}