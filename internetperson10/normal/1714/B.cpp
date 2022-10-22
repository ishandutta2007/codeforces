#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    set<int> s;
    for(int i = n-1; i >= 0; i--) {
        s.insert(nums[i]);
        if(s.size() + i != n) {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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