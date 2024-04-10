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
        for(int i = 0; i < n; i++) cin >> nums[i];
        int g = -1;
        for(int i = 0; i < 30; i++) {
            int k = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] & (1 << i)) k++;
            }
            if(k) {
                if(g == -1) g = k;
                else g = __gcd(g, k);
            }
        }
        if(g == -1) {
            for(int i = 1; i <= n; i++) cout << i << ' ';
            cout << '\n';
        }
        else  {
            for(int i = 1; i <= n; i++) if(!(g%i)) cout << i << ' ';
            cout << '\n';
        }
    }
}