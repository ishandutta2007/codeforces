#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> v, v2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    v.resize(r);
    v2.resize(r);
    for(int i = 0; i < r; i++) {
        v[i].resize(c);
        v2[i].resize(c);
        string s;
        cin >> s;
        for(int j = 0; j < c; j++) {
            if(s.at(j) == 'X') v[i][j] = 1;
            else v[i][j] = 0;
            if(i > 0 && j > 0) {
                if(v[i-1][j] && v[i][j-1]) v2[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(i > 0 && j > 0) {
                v2[i][j] += (v2[i-1][j] + v2[i][j-1] - v2[i-1][j-1]);
            }
            else if(i > 0) {
                v2[i][j] += v2[i-1][j];
            }
            else if(j > 0) {
                v2[i][j] += v2[i][j-1];
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(x == y) {
            cout << "YES\n";
        }
        else if(x < 0) {
            cout << (v2[r-1][y] ? "NO\n" : "YES\n");
        }
        else {
            cout << (v2[r-1][y] - v2[r-1][x] ? "NO\n" : "YES\n");
        }
    }
}