#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int cnt = 0;
    int cur = 0;
    vector<int> y;
    int i = 0;
    for (int x : v) {
        if (cur != x) {
            cnt++;
            cur = 1;
            y.push_back(i);
        }
        cur++;
        i++;
    }
    cout << cnt << '\n';
    int last = n;
    reverse(y.begin(), y.end());
    vector<int> z;
    for (int x : y) {
        z.push_back(last - x);
        last = x;
    }
    reverse(z.begin(), z.end());
    for (auto x : z) {
        cout << x << ' ';
    }
    cout << '\n';
}