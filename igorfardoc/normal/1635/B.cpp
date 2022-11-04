#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> bad(n, false);
        for(int i = 1; i < n - 1; i++) {
            if(a[i] > a[i - 1] && a[i] > a[i + 1]) bad[i] = true;
        }
        int i = 0;
        int ans = 0;
        while(i < n) {
            if(bad[i]) {
                if(i + 2 < n && bad[i + 2]) {
                    a[i + 1] = max(a[i], a[i + 2]);
                    i = i + 3;
                    ++ans;
                    continue;
                } else {
                    a[i] = max(a[i + 1], a[i - 1]);
                    ++ans;
                }
            }
            ++i;
        }
        cout << ans << '\n';
        for(const auto& el : a) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}