#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int n = int(s.size());
    map<char, P> dir;
    dir['U'] = P(0, 1);
    dir['D'] = P(0, -1);
    dir['R'] = P(1, 0);
    dir['L'] = P(-1, 0);

    P ans(0, 0);

    for(int i = 0; i < n; i++) {
        P block(0, 0);
        for(int j = 0; j <= i; j++) {
            block.first += dir[s[j]].first;
            block.second += dir[s[j]].second;
        }
        P now(0, 0);
        for(int j = 0; j < n; j++) {
            P nxt = now;
            nxt.first += dir[s[j]].first;
            nxt.second += dir[s[j]].second;
            if(nxt == block) continue;
            now = nxt;
        }
        if(now == P(0, 0)) { ans = block; }
    }

    cout << ans.first << " " << ans.second << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
}