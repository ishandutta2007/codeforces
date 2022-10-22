#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums1, nums2;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t, m, n, x, y;
    long double k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n;
        for(int i = 0; i < 2*n; i++) {
            cin >> x >> y;
            if(x == 0) nums2.push_back(abs(y));
            else nums1.push_back(abs(x));
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < n; i++) {
            long double b1 = sqrt((long double)(nums1[i]*nums1[i] + nums2[i]*nums2[i]));
            ans += b1;
        }
        cout << fixed << setprecision(12) << ans << '\n';
        vector<ll>().swap(nums1);
        vector<ll>().swap(nums2);
    }
}