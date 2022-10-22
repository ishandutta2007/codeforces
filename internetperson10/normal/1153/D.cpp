#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n), nums(n), ct(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]) ct[i] = -9999999;
        else ct[i] = 1;
    }
    for(int i = 1; i < n; i++) cin >> nums[i];
    for(int i = n-1; i > 0; i--) {
        nums[i]--;
        s.insert(nums[i]);
        if(s.find(i) == s.end()) ct[i] = 0;
        if(v[nums[i]]) ct[nums[i]] = max(ct[nums[i]], ct[i]);
        else ct[nums[i]] += (ct[i] - 1);
    }
    cout << n - s.size() + ct[0] << '\n';
}