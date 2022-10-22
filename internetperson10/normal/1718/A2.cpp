#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> v, ct;
    int x = 0;
    int ans = 0;
    int c = 1;
    set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        x ^= nums[i];
        if(s.count(x)) {
            s.clear();
            x = 0;
            s.insert(0);
        }
        else {
            s.insert(x);
            ans++;
        }
    }
    cout << ans << '\n';
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