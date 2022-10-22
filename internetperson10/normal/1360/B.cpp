#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 6969;
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for(int i = 0; i < n-1; i++) ans = min(ans, v[i+1] - v[i]);
        cout << ans << '\n';
        vector<int>().swap(v);
    }
}