#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> nexts[10];
int origs[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> nums(n+2, vector<int>(m+2, -2));
    vector<int> speed(p), currSpeed(p);
    for(int &s : speed) cin >> s;
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= m+1; j++) {
            nums[i][j] = -2;
        }
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') {
                continue;
            }
            nums[i+1][j+1] = -1;
            if(s[j] != '.') {
                origs[i+1][j+1] = 1;
                nexts[s[j] - '1'].push({i+1, j+1});
            }
        }
    }
    int currP = -1;
    int sadCount = 0;
    while(sadCount != p) {
        bool ok = false;
        currP = (currP + 1) % p;
        int g = 0;
        if(currSpeed[currP] == 0) {
            currSpeed[currP] = 1;
            g = -1;
        }
        for(int z = g; z < speed[currP]; z++) {
            if(nexts[currP].size() == 0) break;
            int pCount = nexts[currP].size();
            pair<int, int> p;
            if(z == -1) {
                while(pCount--) {
                    p = nexts[currP].front();
                    nexts[currP].pop();
                    ok = true;
                    nums[p.first][p.second] = currP;
                    for(int i = 0; i < 4; i++) {
                        int x = p.first + dx[i];
                        int y = p.second + dy[i];
                        if(nums[x][y] != -1 || origs[x][y]) continue;
                        nexts[currP].push({x, y});
                    }
                }
                continue;
            }
            while(pCount--) {
                p = nexts[currP].front();
                nexts[currP].pop();
                if(nums[p.first][p.second] != -1) continue;
                ok = true;
                nums[p.first][p.second] = currP;
                for(int i = 0; i < 4; i++) {
                    int x = p.first + dx[i];
                    int y = p.second + dy[i];
                    if(nums[x][y] != -1 || origs[x][y]) continue;
                    nexts[currP].push({x, y});
                }
            }
        }
        if(ok) sadCount = 0;
        else sadCount++;
    }
    vector<int> cts(p);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i+1][j+1] == -2) continue;
            cts[nums[i+1][j+1]]++;
        }
    }
    for(int g : cts) cout << g << ' ';
}