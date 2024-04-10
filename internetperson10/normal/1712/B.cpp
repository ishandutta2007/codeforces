#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i+1;
    for(int i = n-1; i > 0; i -= 2) swap(v[i], v[i-1]);
    for(int i = 0; i < n; i++) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}