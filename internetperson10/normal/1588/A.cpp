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
        vector<int> nums1(n), nums2(n);
        for(int i = 0; i < n; i++) cin >> nums1[i];
        for(int i = 0; i < n; i++) cin >> nums2[i];
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(nums1[i] != nums2[i] && nums1[i]+1 != nums2[i]) ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}