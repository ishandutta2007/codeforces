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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int can = 0;
    int amL = 0;
    int amR = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            ++amR;
            continue;
        }
        int need = amL;
        can += i - need;
        ++amL;
    }
    if(k > can) {
        cout << -1;
        return 0;
    }
    vvi ans;
    while(can > 0 && k > 0) {
        int canhere = 0;
        vi all;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'R' && s[i + 1] == 'L') {
                ++canhere;
                all.push_back(i);
            }
        }
        for(const auto& el : all) {
            s[el] = 'L';
            s[el + 1] = 'R';
        }
        if(can - canhere >= k - 1) {
            ans.push_back(all);
            can -= canhere;
            k--;
            continue;
        }
        int need = k - can + canhere;
        k -= need;
        can -= canhere;
        for(int i = 0; i < need - 1; i++) {
            ans.push_back({all[i]});
        }
        ans.push_back({});
        for(int i = need - 1; i < all.size(); i++) {
            ans[ans.size() - 1].push_back(all[i]);
        }
    }
    if(k != 0 || can != 0) {
        cout << -1;
        return 0;
    }
    for(const auto& el : ans) {
        cout << el.size() << ' ';
        for(const auto& el1 : el) {
            cout << el1 + 1 << ' ';
        }
        cout << '\n';
    }
}