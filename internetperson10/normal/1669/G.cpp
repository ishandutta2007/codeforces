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
        vector<vector<char>> grid(r);
        for(int i = 0; i < r; i++) {
            grid[i].resize(c);
            string s;
            cin >> s;
            for(int j = 0; j < c; j++) {
                grid[i][j] = s[j];
            }
        }
        for(int j = 0; j < c; j++) {
            int lastFree = r - 1;
            for(int i = r - 1; i >= 0; i--) {
                if(grid[i][j] == 'o') {
                    lastFree = i - 1;
                }
                if(grid[i][j] == '*') {
                    grid[i][j] = '.';
                    grid[lastFree][j] = '*';
                    lastFree--;
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
}