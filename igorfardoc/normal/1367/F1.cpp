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
        vector<pair<int, int>> all;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            all.push_back({a[i], i});
        }
        sort(all.begin(), all.end());
        for(int i = 0; i < n; i++) {
            a[all[i].second] = i;
        }
        vi ans(n, 0);
        int max1 = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                ans[a[i]] = 1;
            } else {
                ans[a[i]] = ans[a[i] - 1] + 1;
            }
            max1 = max(max1, ans[a[i]]);
        }
        cout << n - max1 << '\n';
    }
}