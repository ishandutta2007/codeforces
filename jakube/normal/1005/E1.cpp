#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int idx = find(v.begin(), v.end(), m) - v.begin();
    map<int, int> before;
    before[0] = 1;
    int x = 0;
    for (int i = idx - 1; i >= 0; i--) {
        if (v[i] > m)
            x++;
        else
            x--;
        before[x]++;
    }
    long long res = before[0];
    res += before[1];
    x = 0;
    for (int i = idx + 1; i < n; i++) {
        if (v[i] > m)
            x++;
        else
            x--;
        res += before[-x];
        res += before[-x+1];
    }
    cout << res << '\n';
}