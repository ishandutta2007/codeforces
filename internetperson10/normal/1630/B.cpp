#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        vector<int> ct(n+1);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            ct[nums[i]]++;
        }
        for(int i = 1; i <= n; i++) {
            ct[i] += ct[i-1];
        }
        int l = 0, r = n;
        int curr = n+1;
        int ex = -1, ey = -1;
        while(l != r - 1) {
            int x = (l + r + 1)/2;
            bool ok = false;
            for(int i = 0; i <= n - x; i++) {
                int tot = ct[i+x] - ct[i];
                if(tot - (n - tot) >= k) {
                    ok = true;
                    ex = i+1;
                    ey = i+x;
                }
            }
            if(ok) r = x;
            else l = x;
        }
        if(ex < 0) {
            ex = 1;
            ey = n;
        }
        cout << ex << ' ' << ey << '\n';
        int j = 0;
        int numGood = 0;
        k--;
        for(int i = 0; i < n; i++) {
            if(ex <= nums[i] && nums[i] <= ey) numGood++;
            else numGood--;
            if(numGood > 0 && k) {
                k--;
                cout << j+1 << ' ' << i+1 << '\n';
                j = i+1;
                numGood = 0;
            }
        }
        cout << j+1 << ' ' << n << '\n';
    }
}