#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n <= 3) {
        cout << 1 << '\n';
        return 0;
    }
    map<int, int> ma;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ma[nums[i] + nums[j]]++;
        }
    }
    int ans = 1;
    for(auto p : ma) {
        ans = max(ans, p.second);
    }
    cout << ans << '\n';
}