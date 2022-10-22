#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int nums[1001][1001];
bool ctd[1001][1001];

int valid(int i, int j) {
    int m = max(max(nums[i][j], nums[i][j+1]), max(nums[i+1][j], nums[i+1][j+1]));
    for(int x = i; x < i+2; x++) {
        for(int y = j; y < j+2; y++) {
            if(nums[x][y] != -1 && nums[x][y] != m) return false;
        }
    }
    ctd[i][j] = true;
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            if(valid(i, j)) q.push({i, j});
        }
    }
    vector<pair<pair<int, int>, int>> ops;
    while(q.size()) {
        auto p = q.front(); q.pop();
        int em = valid(p.first, p.second);
        if(em != -1) ops.push_back({{p.first + 1, p.second + 1}, em});
        for(int x = p.first; x < p.first + 2; x++) {
            for(int y = p.second; y < p.second + 2; y++) {
                nums[x][y] = -1;
            }
        }
        for(int x = max(p.first-1, 0); x < min(p.first+2, n); x++) {
            for(int y = max(p.second-1, 0); y < min(p.second+2, m); y++) {
                if(!ctd[x][y]) {
                    if(valid(x, y)) q.push({x, y});
                }
            }
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i][j] != -1) ok = false;
        }
    }
    if(!ok) cout << "-1\n";
    else {
        cout << ops.size() << '\n';
        reverse(ops.begin(), ops.end());
        for(auto p : ops) cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
    }
}