#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int mi = 1e9 + 7;
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(mi > nums[i]) {
                mi = nums[i];
            }
        }
        if(n%2) {
            cout << "Mike\n";
            continue;
        }
        for(int i = 0; i < n; i++) {
            if(mi == nums[i]) {
                cout << ((i % 2) ? "Mike\n" : "Joe\n");
                break;
            }
        }
    }
}