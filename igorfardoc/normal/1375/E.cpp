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
    vector<pair<int, int>> ans;
    for(int i = n - 1; i >= 0; i--) {
        vector<pair<int, int>> val;
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) {
                val.push_back({a[j], j});
            }
        }
        sort(val.begin(), val.end());
        for(auto& el : val) {
            ans.push_back({el.second, i});
            swap(a[el.second], a[i]);
        }
    }
    cout << ans.size() << '\n';
    for(auto& el : ans) {
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
    }
}