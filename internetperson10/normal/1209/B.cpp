#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> nums(n);
    vector<pair<int, int>> p(n);
    int ans = 0, tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        if(s[i] == '1') {
            nums[i] = 1;
            tot++;
        }
        swap(p[i].first, p[i].second);
    }
    ans = tot;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < n; j++) {
            if((p[j].first % p[j].second) == (i % p[j].second) && i >= p[j].first) {
                if(nums[j]) tot--;
                else tot++;
                nums[j] = 1 - nums[j];
            }
        }
        ans = max(ans, tot);
    }
    cout << ans << '\n';
}