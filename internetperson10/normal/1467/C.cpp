#include <bits/stdc++.h>

using namespace std;

vector<long long int> nums1, nums2, nums3;
const long long int BIG = 9999999999;

int main() {
    int t;
    long long int n, k=0, a, b, c, d, e, f;
    a = b = c = d = e = f = 0;
    int x, y, z;
    cin >> x >> y >> z;
    nums1.resize(x);
    nums2.resize(y);
    nums3.resize(z);
    for(int i = 0; i < x; i++) {
        cin >> nums1[i];
        d += nums1[i];
        k += nums1[i];
    }
    for(int i = 0; i < y; i++) {
        cin >> nums2[i];
        e += nums2[i];
        k += nums2[i];
    }
    for(int i = 0; i < z; i++) {
        cin >> nums3[i];
        f += nums3[i];
        k += nums3[i];
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    sort(nums3.begin(), nums3.end());
    cout << k - 2 * min(min(min(nums1[0] + nums2[0], nums1[0] + nums3[0]), min(nums2[0] + nums3[0], d)), min(e, f));
}