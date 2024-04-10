#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll MOD = 1111169;
vector<ll> num, nums;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y = 1;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            num.push_back(x);
        }
        nums = num;
        sort(nums.begin(), nums.end());
        nums.push_back(999999999);
        x = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] != nums[i+1]) y++;
            else y = 0;
            if(y == 2) {
                x = nums[i];
                break;
            }
        }
        if(n == 1) x = 1;
        if(x == -1) cout << -1 << '\n';
        else {
            for(int i = 0; i < n; i++) {
                if(num[i] == x) {
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
        vector<ll>().swap(num);
    }
}