#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        vector<int> a;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += x/k;
            a.push_back(x%k);
        }
        sort(a.begin(), a.end());
        int j = n-1, i = 0;
        while(i < j) {
            if(a[i] + a[j] < k) {
                i++;
            }
            else {
                ans++;
                i++;
                j--;
            }
        }
        cout << ans << '\n';
    }
}