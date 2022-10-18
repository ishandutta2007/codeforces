#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s, t;
    cin >> n >> s >> t;
    
    map<char, map<char, int>> index;
    int hd = 0;
    for (int i = 0; i < n; i++) {
        char x = s[i];
        char y = t[i];
        if (x != y) {
            index[x][y] = i;
            hd++;
        }
    }

    using Result = array<int, 3>;  // hd, index1, index2
    Result best = {hd, -1, -1};
    // first try perfect match
    for (int i = 0; i < n; i++) {
        char x = s[i];
        char y = t[i];
        if (x != y) {
            if (index.count(y)) {
                Result r;
                if (index[y].count(x))
                    r = {hd - 2, i + 1, index[y][x] + 1};
                else
                    r = {hd - 1, i + 1, index[y].begin()->second + 1};
                best = min(best, r);
            }
        }
    }
    cout << best[0] << '\n';
    cout << best[1] << ' ' << best[2] << '\n';
}