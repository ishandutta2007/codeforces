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
        vvi pos(n + 1);
        vi b(n);
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            b[i] = a;
            pos[a].push_back(i);
        }
        for(int i = 0; i <= n; i++) {
            reverse(pos[i].begin(), pos[i].end());
        }
        vi ans;
        int am = n;
        int fir = 0;
        int now = 0;
        while(am > 0) {
            if(pos[0].empty()) {
                while(pos[fir].empty()) {
                    ++fir;
                }
                pos[fir].pop_back();
                ans.push_back(0);
                --am;
                continue;
            }
            int here = 0;
            int posmax = 0;
            while(here <= n && pos[here].size() > 0) {
                posmax = max(posmax, pos[here][pos[here].size() - 1]);
                ++here;
            }
            while(now <= posmax) {
                pos[b[now]].pop_back();
                --am;
                ++now;
            }
            ans.push_back(here);

        }
        cout << ans.size() << '\n';
        for(const auto& el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}