#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    // Min: it's always the smallest one reachable
    for(int i = 0; i < n; i++) {
        int l = -1, r = n-1;
        while(l != r - 1) {
            int x = (l + r + 1) / 2;
            if(b[x] < a[i]) l = x;
            else r = x;
        }
        cout << b[r] - a[i] << ' ';
    }
    cout << '\n';
    // Max: calculate "cliques", where the last x elements must go to the last x elements
    vector<int> ans;
    ans.push_back(b[n-1] - a[n-1]);
    int x = n-1;
    for(int i = n-2; i >= 0; i--) {
        if(b[i] < a[i+1]) {
            x = i;
        }
        ans.push_back(b[x] - a[i]);
    }
    reverse(ans.begin(), ans.end());
    for(int g : ans) {
        cout << g << ' ';
    }
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