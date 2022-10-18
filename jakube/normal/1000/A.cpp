#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(4, vector<int>(3, 0));
    for (int i = 0; i < 2*n; i++) {
        string s;
        cin >> s;
        int x = count(s.begin(), s.end(), 'X');
        int size = s.back() == 'L' ? 0 : s.back() == 'M' ? 1 : 2;
        if (i < n)
            v[x][size]++;
        else
            v[x][size]--;
    }

    int cnt = 0;
    for (auto row : v) {
        int m = 0;
        for (int i : row)
            m = max(m, abs(i));
        cnt += m;
    }
    cout << cnt << '\n';
}