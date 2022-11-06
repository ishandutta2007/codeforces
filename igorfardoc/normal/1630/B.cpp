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
        int n, k;
        cin >> n >> k;
        vi a(n);
        vi am(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ++am[a[i]];
        }
        int x1 = -1;
        int y1 = n;
        int y = 1;
        int now = 0;
        int amount = 0;
        for(int x = 1; x <= n; x++) {
            while(y <= n && 2 * now - n < k) {
                now += am[y];
                ++y;
            }
            if(2 * now - n < k) break;
            if(y1 - x1 > y - x - 1) {
                x1 = x;
                y1 = y - 1;
                amount = now;
            }
            now -= am[x];
        }
        cout << x1 << ' ' << y1 << '\n';
        vector<pair<int, int>> ans;
        int prev = 0;
        int bal = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] >= x1 && a[i] <= y1) {
                ++bal;
                --amount;
            } else {
                --bal;
            }
            if(bal <= 0) continue;
            if(bal > 0 && (i == n - 1 || 2 * amount - (n - i - 1) > 0)) {
                ans.push_back({prev, i});
                prev = i + 1;
                bal = 0;
            }
        }
        while(ans.size() > k) {
            int r = ans[ans.size() - 1].second;
            ans.pop_back();
            ans[ans.size() - 1].second = r;
        }
        for(const auto& el : ans) {
            cout << el.first + 1 << ' ' << el.second + 1 << '\n';
        }
    }

}