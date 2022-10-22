#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums;
vector<pair<pair<int, int>, int>> v;

void shift(int l, int r, int c) {
    v.push_back({{l+1, r+1}, c});
    for(int i = 0; i < c; i++) {
        for(int j = l; j < r; j++) {
            swap(nums[j], nums[j+1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        nums.resize(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = 0; i < n-1; i++) {
            int x = 1234567890;
            for(int j = i; j < n; j++) {
                x = min(x, nums[j]);
            }
            for(int j = i; j < n; j++) {
                if(x == nums[j]) {
                    if(j-i) shift(i, n-1, j-i);
                    break;
                }
            }
        }
        cout << v.size() << '\n';
        for(int i = 0; i < v.size(); i++) cout << v[i].first.first << ' ' << v[i].first.second << ' ' << v[i].second << '\n';
        vector<int>().swap(nums);
        vector<pair<pair<int, int>, int>>().swap(v);
    }
}