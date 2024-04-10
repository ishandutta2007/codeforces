#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ma = -1;
    vector<ll> nums(n);
    ll sum = 0;
    ll lim = -1;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        ma = max(ma, nums[i]);
        if(i) nums[i] += nums[i-1];
        sum = nums[i];
        lim = max(lim, (sum + i) / (i+1));
    }
    int q;
    cin >> q;
    while(q--) {
        ll t;
        cin >> t;
        if(t < lim) {
            cout << "-1\n";
        }
        else {
            cout << (sum + t - 1) / t << '\n';
        }
    }
}