#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums1, nums2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0, x, y;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            nums1.push_back(x);
            nums2.push_back(y);
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if(n%2) {
            cout << 1 << '\n';
        }
        else {
            cout << (nums1[n/2]-nums1[n/2-1]+1)*(nums2[n/2]-nums2[n/2-1]+1) << '\n';
        }
        vector<ll>().swap(nums1);
        vector<ll>().swap(nums2);
    }
}