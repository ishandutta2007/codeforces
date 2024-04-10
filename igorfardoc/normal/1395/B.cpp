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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    set<pair<int, int>> s;
    cout << x << ' ' << y << '\n';
    cout << 1 << ' ' << y << '\n';
    cout << 1 << ' ' << 1 << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if((i != x || j != y) && (i != 1 || j != y) && (i != 1 || j != 1)) {
                s.insert({i, j});
            }
        }
    }
    int now = 1;
    int now1 = 1;
    while(!s.empty()) {
        auto it = s.begin();
        if((*it).second == 1) {
            if(s.size() != 1) {
                ++it;
                if((*it).first != now) {
                    --it;
                }
            }
        }
        cout << (*it).first << ' ' << (*it).second << '\n';
        now1 = (*it).second;
        now = (*it).first;
        s.erase(it);
        if(now1 == 1 || now1 == m) {
            if(s.size() > 0) {
                ++now;
                cout << now << ' ' << now1 << '\n';
                s.erase(s.find({now, now1}));
            }
        }
    }
}