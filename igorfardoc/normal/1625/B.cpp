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
        map<int, vi> p;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            p[a[i]].push_back(i);
        }
        int ans = -1;
        for(const auto& el : p) {
            for(int i = 0; i < (int)el.second.size() - 1; i++) {
                ans = max(ans, n - el.second[i + 1] + el.second[i]);
            }
        }
        cout << ans << '\n';
    }
}