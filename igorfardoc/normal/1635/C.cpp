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
        if(a[n - 1] < a[n - 2]) {
            cout << -1 << '\n';
            continue;
        }
        int mn = a[n - 2] - a[n - 1];
        int id = n - 2;
        vector<array<int, 3>> ans;
        bool ok = true;
        for(int i = n - 3; i >= 0; i--) {
            if(mn <= a[i + 1]) {
                for(int j = i; j >= 0; j--) {
                    ans.push_back({j, id, n - 1});
                }
                break;
            }
            if(a[i] > a[i + 1]) {
                ok = false;
                break;
            }
            mn = a[i] - a[n - 1];
            id = i;
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for(const auto& el : ans) {
            cout << el[0] + 1 << ' ' << el[1] + 1 << ' ' << el[2] + 1 << '\n';
        }
    }
}