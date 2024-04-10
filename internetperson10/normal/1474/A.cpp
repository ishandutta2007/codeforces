#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums, nums2, nums3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    long long int k, a, b, c, d, e, w, x, y, z, ans=0;
    string s1;
    cin >> t;
    while(t--) {
        c = -1;
        cin >> n >> s1;
        for(int i = 0; i < n; i++) {
            x = (int)(s1.at(i)-'0');
            if(c != x+1) {
                nums.push_back(1);
                c = x+1;
            }
            else {
                nums.push_back(0);
                c = x;
            }
        }
        for(int i = 0; i < n; i++) cout << nums[i];
        cout << '\n';
        vector<ll>().swap(nums);
    }
}