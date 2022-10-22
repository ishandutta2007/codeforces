#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<bool>> robs(r, vector<bool>(c));
        int mina = 999, minb = 999;
        for(int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < c; j++) {
                if(s[j] == 'R') {
                    robs[i][j] = true;
                    mina = min(mina, i);
                    minb = min(minb, j);
                }
            }
        }
        if(robs[mina][minb]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}