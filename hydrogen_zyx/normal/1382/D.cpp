#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int a[5000];
bool dp[5000];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        rep(i, 1, 2 * n) cin >> a[i];
        vector<int> v;
        int i = 1;
        while (i <= 2 * n) {
            int cnt = 0;
            while (i + cnt <= 2 * n && a[i + cnt] <= a[i]) cnt++;
            v.push_back(cnt);
            i += cnt;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        //cout << '*' << ' ';
        rep(i, 0, (int)v.size() - 1) {
            //cout << v[i] << ' ';
            per(j, 3000, 0) {
                if (dp[j]) dp[j + v[i]] = 1;
            }
        }
        //cout << endl;
        if (dp[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}