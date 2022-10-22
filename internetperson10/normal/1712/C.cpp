#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    set<int> bads;
    map<int, int> ct;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        ct[nums[i]]++;
    }
    int max_sorted = 0;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] > nums[i+1]) {
            max_sorted = i+1;
            break;
        }
    }
    int tot = 0;
    for(int i = 0; i < n; i++) {
        if(bads.count(nums[i])) continue;
        if(i < max_sorted || tot > i) {
            bads.insert(nums[i]);
            tot += ct[nums[i]];
        }
    }
    cout << bads.size() << '\n';
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