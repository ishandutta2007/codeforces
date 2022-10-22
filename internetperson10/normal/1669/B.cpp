#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n+2);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums[x]++;
        }
        for(int i = 1; i <= n+1; i++) {
            if(i == n+1) {
                cout << "-1\n";
            }
            else if(nums[i] > 2) {
                cout << i << '\n';
                break;
            }
        }
    }
}