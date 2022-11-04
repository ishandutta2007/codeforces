#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first < b.first) {
        return true;
    }
    if(b.first < a.first) {
        return false;
    }
    return a.second > b.second;
}

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
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), cmp);
        ll ans = 0;
        int now = 0;
        multiset<int> all;
        for(int i = n - 1; i >= 0; i--) {
            all.insert(a[i].second);
            while(a[i].first - i - now > 0) {
                ++now;
                ans += *(all.begin());
                all.erase(all.begin());
            }
        }
        cout << ans << '\n';
    }
}