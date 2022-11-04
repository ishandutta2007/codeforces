#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll get_sum(int a, int b) {
    if(a > b) return 0;
    ll res = (ll)b * (b + 1) / 2;
    res -= (ll)a * (a - 1) / 2;
    return res;
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
        vi k(n), h(n);
        for(int i = 0; i < n; i++) {
            cin >> k[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<pair<int, int>> otr;
        for(int i = 0; i < n; i++) {
            otr.push_back({k[i] - h[i] + 1,  k[i]});
        }
        sort(otr.begin(), otr.end());
        ll ans = 0;
        int l = 0;
        int r = -1;
        for(int i = 0; i < n; i++) {
            if(otr[i].first > r) {
                ans += get_sum(1, r - l + 1);
                l = otr[i].first;
                r = otr[i].second;
            } else {
                r = max(r, otr[i].second);
            }
        }
        //cout << l << ' ' << r << endl;
        ans += get_sum(1, r - l + 1); 
        cout << ans << '\n';
    }

}