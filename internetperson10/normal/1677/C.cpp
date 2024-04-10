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
        vector<int> numsa(n), numsb(n);
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> numsa[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> nums[numsa[i]-1];
            nums[numsa[i]-1]--;
        }
        vector<ll> cycs;
        for(int i = 0; i < n; i++) {
            if(nums[i] == -1) continue;
            int x = i;
            x = nums[i];
            nums[i] = -1; 
            int g = 1;
            while(x != i) {
                g++;
                int y = x;
                x = nums[x];
                nums[y] = -1;
            }
            cycs.push_back((g/2));
        }
        sort(cycs.rbegin(), cycs.rend());
        ll x = n;
        ll ans = 0;
        for(ll g : cycs) {
            ans += (x - g) * g * 2;
            x -= (2 * g);
        }
        cout << ans << endl;
    }
}