#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> nums;
        nums.push_back({-1, -1});
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int g = 1;
            while(!(x%k)) {
                x /= k;
                g *= k;
            }
            if(nums.back().first != x) {
                nums.push_back({x, g});
            }
            else {
                nums.back().second += g;
            }
        }
        int m;
        cin >> m;
        vector<pair<ll, ll>> nums2;
        nums2.push_back({-1, -1});
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            int g = 1;
            while(!(x%k)) {
                x /= k;
                g *= k;
            }
            if(nums2.back().first != x) {
                nums2.push_back({x, g});
            }
            else {
                nums2.back().second += g;
            }
        }
        if(nums == nums2) {
            cout << "Yes\n";
        }
        else {
            cout << "NO\n";
        }
    }
}