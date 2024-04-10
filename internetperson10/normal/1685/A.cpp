#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int &g : nums) cin >> g;
        if(n%2) {
            cout << "NO\n";
            continue;
        }
        sort(nums.begin(), nums.end());
        bool ok = true;
        for(int i = 0; i < n/2; i++) {
            if(nums[i] == nums[i + n/2]) {
                ok = false;
            }
            if(nums[1+i] == nums[i + n/2] && i < (n-2)/2) {
                ok = false;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n/2; i++) {
            cout << nums[i] << ' ' << nums[n/2 + i] << ' ';
        }
        cout << '\n';
    }
}