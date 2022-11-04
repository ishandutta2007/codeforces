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
        if(a[0] != n && a[n - 1] != n) {
            cout << "-1\n";
            continue;
        }
        vi ans(n);
        ans[0] = n;
        int now = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == n) {
                continue;
            }
            ans[now++] = a[i];
        }
        for(const auto& el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}