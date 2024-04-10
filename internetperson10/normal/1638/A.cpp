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
        vector<int> nums(n);
        bool ok = false;
        int g = 0, x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(ok && nums[i] == g) {
                x = g-1;
                y = i;
            }
            if(ok == false && nums[i] != i+1) {
                ok = true;
                g = i+1;
            }
        }
        for(int i = x; i <= (x+y)/2; i++) swap(nums[i], nums[x+y-i]);
        for(int i = 0; i < n; i++) cout << nums[i] << ' ';
        cout << '\n';
    }
}