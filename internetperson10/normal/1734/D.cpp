#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;
    vector<ll> nums;
    int g = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(nums.size() == 0) nums.push_back(x);
        else if(x < 0) {
            if(nums.back() < 0) nums.back() += x;
            else nums.push_back(x);
        }
        else {
            if(nums.back() >= 0) nums.back() += x;
            else nums.push_back(x);
        }
        if(i == k) g = nums.size() - 1;
    }
    k = g;
    int l = k-1, r = k+1;
    ll min_l = 0, min_r = 0, sum_l = 0, sum_r = 0, curr_sum = nums[k];
    auto go_left = [&]() {
        min_l = sum_l = 0;
        while(l != -1) {
            sum_l += nums[l];
            min_l = min(min_l, sum_l);
            l--;
            if(sum_l >= 0) break;
        }
    };
    auto go_right = [&]() {
        min_r = sum_r = 0;
        while(r != (int)nums.size()) {
            sum_r += nums[r];
            min_r = min(min_r, sum_r);
            r++;
            if(sum_r >= 0) break;
        }
    };
    bool ok = false, moved = true;
    go_left();
    go_right();
    while(moved && !ok) {
        moved = false;
        if(curr_sum + min_l >= 0 && (sum_l >= 0 || l == -1)) {
            curr_sum += sum_l;
            if(l == -1) ok = true;
            go_left();
            moved = true;
        }
        if(curr_sum + min_r >= 0 && (sum_r >= 0 || r == nums.size())) {
            curr_sum += sum_r;
            if(r == nums.size()) ok = true;
            go_right();
            moved = true;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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