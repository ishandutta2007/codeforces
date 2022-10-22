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
        vector<ll> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        if(n <= 10) {
            set<ll> s;
            for(int i = 0; i < n; i++) {
                s.insert(nums[i]);
            }
            bool ok = true;
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    for(int k = j+1; k < n; k++) {
                        if(!s.count(nums[i] + nums[j] + nums[k])) ok = false;
                    }
                }
            }
            if(ok) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            bool ok = true;
            for(int i = 1; i < n-1; i++) {
                if(nums[i]) ok = false;
            }
            if(nums[0] + nums[n-1] && nums[0] && nums[n-1]) ok = false;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}