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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_map<int, int> d;
        for(int i = 0; i < n; i++) {
            d[(k - a[i] % k) % k]++;
        }
        ll ans = 0;
        for(const auto& el : d) {
            if(el.first == 0) {
                continue;
            }
            ans = max(ans, (ll)(el.second - 1) * k + el.first + 1);
        }
        cout << ans << '\n';
    } 
}