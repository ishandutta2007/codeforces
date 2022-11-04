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
        int n, m;
        cin >> n >> m;
        ll ans = 0;
        vi a(m), b(m);
        vector<bool> used(m, false);
        map<int, vector<int>> da, db;
        set<int, greater<int>> all;
        for(int i = 0; i < m; i++) {
            cin >> a[i] >> b[i];
            all.insert(a[i]);
            all.insert(b[i]);
            da[a[i]].push_back(i);
            db[b[i]].push_back(i);
        }
        ll now = 0;
        for(const auto& value : all) {
            for(const auto& el : da[value]) {
                if(n > 0) {
                    --n;
                    used[el] = true;
                    now += a[el];
                }
            }
            ans = max(ans, now);
            if(n == 0) {
                break;
            }
            for(const auto& el : db[value]) {
                if(n > 0) {
                    if(used[el]) {
                        now += (ll)n * b[el];
                        n = 0;
                        break;
                    } else {
                        ans = max(ans, now + a[el] + (ll)(n - 1) * b[el]);
                    }
                }
            }
            ans = max(ans, now);
            if(n == 0) {
                break;
            }
        }
        cout << ans << '\n';
    }

}