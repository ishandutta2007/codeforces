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
        vi a(n);
        map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        set<pair<int, int>> ban;
        for(int i = 0; i < m; i++) {
            int v, u;
            cin >> v >> u;
            ban.insert({v, u});
        }
        vvi here(n + 1);
        map<int, int> where;
        set<int> cnts;
        for(const auto& el : cnt) {
            cnts.insert(el.second);
            here[el.second].push_back(el.first);
            where[el.first] = here[el.second].size() - 1;
        }
        vi cnts1;
        for(const auto& el : cnts) {
            cnts1.push_back(el);
        }
        ll ans = 0;
        for(int i = 0; i < cnts1.size(); i++) {
            if(here[cnts1[i]].size() > 1) {
                pair<int, int> p = {here[cnts1[i]].back(), here[cnts1[i]][here[cnts1[i]].size() - 2]};
                if(p.first > p.second) swap(p.first, p.second);
                if(ban.find(p) == ban.end()) {
                    ans = max(ans, (ll)(cnts1[i] + cnts1[i]) * (p.first + p.second));
                }
            }
            for(int j = i + 1; j < cnts1.size(); j++) {
                pair<int, int> p = {here[cnts1[i]].back(), here[cnts1[j]].back()};
                if(p.first > p.second) swap(p.first, p.second);
                if(ban.find(p) == ban.end()) {
                    ans = max(ans, (ll)(cnts1[i] + cnts1[j]) * (p.first + p.second));
                }
            }
        }
        for(const auto& el : ban) {
            int cnt1 = cnt[el.first];
            int cnt2 = cnt[el.second];
            int a = el.first;
            int b = el.second;
            int id1 = where[a];
            int id2 = where[b];
            if(id1 != 0 && (cnt1 != cnt2 || id1 - 1 != id2)) {
                pair<int, int> p = {here[cnt1][id1 - 1], b};
                if(p.first > p.second) swap(p.first, p.second);
                if(ban.find(p) == ban.end()) {
                    ans = max(ans, (ll)(cnt1 + cnt2) * (p.first + p.second));
                }
            }
            if(id2 != 0 && (cnt1 != cnt2 || id2 - 1 != id1)) {
                pair<int, int> p = {a, here[cnt2][id2 - 1]};
                if(p.first > p.second) swap(p.first, p.second);
                if(ban.find(p) == ban.end()) {
                    ans = max(ans, (ll)(cnt1 + cnt2) * (p.first + p.second));
                }
            }
        }
        cout << ans << '\n';
    }

}