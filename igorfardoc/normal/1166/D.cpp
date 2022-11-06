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
        ll a, b, m;
        cin >> a >> b >> m;
        vector<ll> res;
        res.push_back(a);
        ll sum = a;
        while(sum + 1 <= b) {
            res.push_back(sum + 1);
            sum = sum + sum + 1;
        }
        bool ok = false;
        vector<ll> ans;
        for(int len = 1; len <= res.size(); len++) {
            ans.clear();
            auto now = res;
            ll need = b - res[len - 1];
            bool ok1 = true;
            ans.push_back(a);
            for(int i = 1; i < len; i++) {
                int st = max((int)len - i - 2, 0);
                ll val = 1ll << st;
                ll r = min(m - 1, need / val);
                for(int j = i + 1; j < len; j++) {
                    now[j] += r * (1ll << (j - i - 1));
                }
                need -= val * r;
                ans.push_back(now[i] + r);
            }
            if(!ok1) continue;
            if(need == 0) {
                ok = true;
                break;
            }
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << ' ';
        for(const auto& el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}