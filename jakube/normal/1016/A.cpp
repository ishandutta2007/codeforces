#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    long long cur = 0;
    for (auto x : a) {
        cur += x;
        cout << cur / m << " ";
        cur %= m;
    }
    cout << endl;
}