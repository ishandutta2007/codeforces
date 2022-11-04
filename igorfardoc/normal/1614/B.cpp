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
        ll ans = 0;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        vi res(n + 1);
        res[0] = 0;
        sort(a.begin(), a.end());
        int now = 1;
        for(int i = a.size() - 1; i >= 0; i-=2) {
            res[a[i].second + 1] = now;
            ans += (ll)2 * a[i].first * now;
            if(i != 0) {
                res[a[i - 1].second + 1] = -now;
                ans += (ll)a[i - 1].first * 2 * now;
            }
            ++now;
        }
        cout << ans << '\n';
        for(const auto& el : res) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}