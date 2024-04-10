#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll nums[26][26];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ans = 0;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                nums[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            nums[s[0] - 'a'][s[1] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                ans -= 2 * nums[i][j] * nums[i][j];
                for(int k = 0; k < 26; k++) {
                    ans += (nums[i][j] * nums[i][k]);
                    ans += (nums[i][j] * nums[k][j]);
                }
            }
        }
        cout << ans/2 << '\n';
    }
}