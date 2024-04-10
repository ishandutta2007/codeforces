#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    multiset<int> tmp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int bal = 0, minbal = 0, maxbal = 0;
        for (auto c : s) {
            if (c == '(') {
                bal++;
            } else {
                bal--;
            }
            minbal = min(minbal, bal);
            maxbal = max(maxbal, bal);
        }
        if (minbal >= 0) {
            if (tmp.find(-bal) != tmp.end()) {
                tmp.erase(tmp.find(-bal));
                ans++;
            } else {
                tmp.insert(bal);
            }
        } else if (bal == minbal) {
            if (tmp.find(-bal) != tmp.end()) {
                tmp.erase(tmp.find(-bal));
                ans++;
            } else {
                tmp.insert(bal);
            }
        }
    }
    cout << ans;
}