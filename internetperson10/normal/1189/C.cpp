#include <bits/stdc++.h>

using namespace std;

int nums[200001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> nums[i];
    for(int i = 2; i <= n; i++) nums[i] += nums[i-1];
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << (nums[r] - nums[l])/10 << '\n';
    }
}