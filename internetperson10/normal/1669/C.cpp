#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] %= 2;
        }
        bool ok = true;
        for(int i = 2; i < n; i++) {
            if(nums[i] ^ nums[i-2]) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}