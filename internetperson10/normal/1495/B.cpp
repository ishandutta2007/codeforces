#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums, peaks1, peaks2;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t, n, x = 0, mx = 0, m = 0;
    ll k = 0, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> n;
    nums.resize(n);
    peaks1.resize(n);
    peaks2.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 1; i < n; i++) {
        if(i == 1) {
            if(nums[i-1] > nums[i]) {
                k = 1;
                sad = true;
            }
            else k = -1;
        }
        else if(sad) {
            if(nums[i-1] > nums[i]) {
                k++;
            }
            else {
                peaks1[x] = -k;
                peaks2[i-1] = k;
                k = -1;
                x = i-1;
                sad = false;
            }
        }
        else {
            if(nums[i-1] > nums[i]) {
                peaks1[x] = -k;
                peaks2[i-1] = k;
                k = 1;
                x = i-1;
                sad = true;
            }
            else {
                k--;
            }
        }
        if(i == n-1) {
            peaks1[x] = -k;
            peaks2[i] = k;
        }
        if(mx < abs(k)) {
            mx = abs(k);
            m = 1;
        }
        else if(mx == abs(k)) {
            m++;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << nums[i] << ' ' << peaks1[i] << ' ' << peaks2[i] << '\n';
    // }
    // cout << mx << ' ' << m << '\n';
    if(m > 2 || m == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if(m == 2) {
        for(int i = 0; i < n; i++) {
            if(peaks1[i] == peaks2[i] && peaks1[i] == -mx && !(mx%2)) {
                cout << 1 << '\n';
                return 0;
            }
        }
        cout << 0 << '\n';
        return 0;
    }
}