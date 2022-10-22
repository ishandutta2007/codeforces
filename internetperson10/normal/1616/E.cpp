#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        string s1_sort = s1;
        sort(s1_sort.begin(), s1_sort.end());
        if(s1 < s2) {
            cout << "0\n";
            continue;
        }
        if(s1_sort >= s2) {
            cout << "-1\n";
            continue;
        }
        vector<vector<int>> ct(26);
        ordered_set s;
        for(int i = 0; i < n; i++) {
            ct[s1.at(i)-'a'].push_back(i);
            s.insert(i);
        }
        for(int i = 0; i < 26; i++) reverse(ct[i].begin(), ct[i].end());
        ll ans = (ll)n*(ll)n, tot = 0;
        for(int j = 0; j < (s2.at(0) - 'a'); j++) {
            if(ct[j].size()) {
                ans = min(ans, tot + (ll)s.order_of_key(ct[j].back()));
            }
        }
        for(int i = 0; i < n-1; i++) {
            int g = s2.at(i) - 'a';
            if(ct[g].size()) {
                tot += s.order_of_key(ct[g].back());
                s.erase(ct[g].back());
                ct[g].pop_back();
            }
            else break;
            for(int j = 0; j < (s2.at(i+1) - 'a'); j++) {
                if(ct[j].size()) {
                    ans = min(ans, tot + (ll)s.order_of_key(ct[j].back()));
                }
            }
        }
        cout << ans << '\n';
        vector<vector<int>>().swap(ct);
    }

}