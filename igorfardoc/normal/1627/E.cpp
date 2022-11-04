#include<bits/stdc++.h>
#define inf 1000000000000000000ll
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
        int n, m, k;
        cin >> n >> m >> k;
        vi x(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<vector<array<int, 4>>> st(n);
        for(int i = 0; i < k; i++) {
            int a, b, c, d, h;
            cin >> a >> b >> c >> d >> h;
            --a;
            --b;
            --c;
            --d;
            st[c].push_back({d, a, b, h});
        }
        for(int i = 0; i < n; i++) {
            sort(st[i].begin(), st[i].end());
        }
        vector<map<int, ll>> can(n);
        can[n - 1][m - 1] = 0;
        for(int i = n - 1; i >= 0; i--) {
            {
                auto it = can[i].begin();
                int idgood = -1;
                ll val = -inf;
                for(const auto& el : st[i]) {
                    int id1 = el[0];
                    while(it != can[i].end() && it->first <= id1) {
                        if(val - (ll)(id1 - idgood) * x[i] < it->second - (ll)(id1 - it->first) * x[i]) {
                            idgood = it->first;
                            val = it->second;
                        }
                        ++it;
                    }
                    ll here = max(-inf, val - (ll)(id1 - idgood) * x[i]);
                    if(here != -inf) {
                        if(can[el[1]].find(el[2]) == can[el[1]].end()) {
                            can[el[1]][el[2]] = -inf;
                        }
                        can[el[1]][el[2]] = max(can[el[1]][el[2]], el[3] + here);
                    }
                }
            }
            {
                auto it = can[i].rbegin();
                int idgood = m;
                ll val = -inf;
                reverse(st[i].begin(), st[i].end());
                for(const auto& el : st[i]) {
                    int id1 = el[0];
                    while(it != can[i].rend() && it->first >= id1) {
                        if(val - (ll)(idgood - id1) * x[i] < it->second - (ll)(it->first - id1) * x[i]) {
                            idgood = it->first;
                            val = it->second;
                        }
                        ++it;
                    }
                    ll here = max(-inf, val - (ll)(idgood - id1) * x[i]);
                    if(here != -inf) {
                        if(can[el[1]].find(el[2]) == can[el[1]].end()) {
                            can[el[1]][el[2]] = -inf;
                        }
                        can[el[1]][el[2]] = max(can[el[1]][el[2]], el[3] + here);
                    }
                }
            }
        }
        /*for(const auto& el : can[2]) {
            cout << el.first << ' ' << el.second << endl;
        }*/
        ll ans = -inf;
        for(const auto& el : can[0]) {
            ans = max(ans, (ll)(-x[0]) * el.first + el.second);
        }
        if(ans == -inf) {
            cout << "NO ESCAPE\n";
        } else {
            cout << -ans << '\n';
        }
    }

}