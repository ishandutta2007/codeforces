#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums1, nums2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> n >> m >> s1 >> s2;
    nums1.resize(m);
    nums2.resize(m);
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(s1.at(j) != s2.at(i)) j++;
        nums1[i] = j;
        j++;
    }
    j = n-1;
    for(int i = m-1; i >= 0; i--) {
        while(s1.at(j) != s2.at(i)) j--;
        nums2[i] = j;
        j--;
    }
    for(int i = 1; i < m; i++) ans = max(ans, nums2[i] - nums1[i-1]);
    cout << ans << '\n';
}