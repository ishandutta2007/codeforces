#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

map<int, vector<int>> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            ma[x].push_back(i);
        }
        int best = -1;
        int a = -1, l = -1, r = -1;
        for(auto p : ma) {
            int ma = -1e9;
            int ma_index = -1;
            vector<int> v = p.second;
            for(int i = 0; i < v.size(); i++) {
                int val = v[i] - 2 * i;
                if(val > ma) {
                    ma = val;
                    ma_index = v[i];
                }
                if(best < ma - val) {
                    best = ma - val;
                    a = p.first;
                    l = ma_index;
                    r = v[i];
                }
            }
        }
        cout << a << ' ' << l << ' ' << r << '\n';
        ma.clear();
    }
}