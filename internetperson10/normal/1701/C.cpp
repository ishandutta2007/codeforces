#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*



















*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n, 0);
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            x--;
            nums[x]++;
        }
        int l = -1, r = 99999999;
        while(l != r - 1) {
            int mid = (l + r + 1) / 2;
            ll tasks = 0;
            for(int g : nums) {
                if(g > mid) tasks += mid;
                else tasks += g + (mid - g) / 2;
            }
            if(tasks >= m) r = mid;
            else l = mid;
        }
        cout << r << '\n';
    }
}