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
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        ans.push_back({i * 2, 0});
        ans.push_back({i * 2 - 1, 0});
        ans.push_back({i * 2, 1});
        ans.push_back({i * 2, -1});
    }
    ans.push_back({(n - 1) * 2 + 1, 0});
    for(int i = 0; i < n - 1; i+=2) {
        ans.push_back({2 * i, 2});
        ans.push_back({2 * i + 1, 2});
        ans.push_back({2 * i + 2, 2});
    }
    int last = (n - 1) * 2;
    if(n % 2 == 1) {
        ans.push_back({last, 2});
        ans.push_back({last + 1, 2});
        ans.push_back({last + 2, 2});
        ans.push_back({last + 2, 1});
        ans.push_back({last + 2, 0});
        for(int i = n - 1; i > 0; i-=2) {
            ans.push_back({2 * i, -2});
            ans.push_back({2 * i - 1, -2});
            ans.push_back({2 * i - 2, -2});
        }
        ans.push_back({0, -2});
        ans.push_back({-1, -2});
        ans.push_back({-2, -2});
        ans.push_back({-2, -1});
        ans.push_back({-2, 0})
;    } else {
        ans.push_back({last + 2, 0});
        ans.push_back({last + 2, -1});
        ans.push_back({last + 2, -2});
        ans.push_back({last + 1, -2});
        ans.push_back({last, -2});
        for(int i = n - 2; i > 0; i-=2) {
            ans.push_back({2 * i, -2});
            ans.push_back({2 * i - 1, -2});
            ans.push_back({2 * i - 2, -2});
        }
        ans.push_back({0, -2});
        ans.push_back({-1, -2});
        ans.push_back({-2, -2});
        ans.push_back({-2, -1});
        ans.push_back({-2, 0});
    }
    cout << ans.size() << '\n';
    for(auto el : ans) {
        cout << el.first << ' ' << el.second << '\n';
    }

}