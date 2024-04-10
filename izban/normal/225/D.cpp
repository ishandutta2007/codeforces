#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define ll long long


const int maxn = 15;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct state {
    int x, y;
    int mask;

    bool operator< (const state &st) const {
        if (x < st.x) return 1;
        if (x == st.x && y < st.y) return 1;
        if (x == st.x && y == st.y && mask < st.mask) return 1;
        return 0;
    }
};
 
int n, m, mx, ans = 1000000;
string a[maxn];
pair<int, int> dest;
//map<state, int> mp;
int mp[15][15][70000];
vector<vector<char> > VIS;

int Mask(vector<int> v) {
    int res = 0;
    for (int i = 0; i < mx-1; i++)
        res = res*4 + v[i];
    return res;
}

vector<int> vct(int mask) {
    vector<int> res;
    for (int i = 0; i < mx-1; i++) {
        res.push_back(mask % 4);
        mask /= 4;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    cin >> n >> m;
    VIS.assign(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++)
            if (a[i][j] >= '1' && a[i][j] <= '9')
                mx = max(mx, a[i][j]-'0');
    }
    
    vector<int> v(mx-1);
    state start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') 
                dest = make_pair(i, j);
            if (a[i][j] >= '1' && a[i][j] <= '9' && a[i][j] < '0' + mx) {
                for (int k = 0; k < 4; k++)
                    if (i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m && a[i+dx[k]][j+dy[k]]==a[i][j]+1)
                        v[a[i][j]-'1'] = k;
                if (a[i][j] == '1')
                    start.x = i, start.y = j;
            }
            if (a[i][j] == '#')
                VIS[i][j] = -1;
        }
    }

    start.mask = Mask(v);
    queue<state> q;
    q.push(start);
    mp[start.x][start.y][start.mask] = 1;
    while (!q.empty()) {
        state cur = q.front();
        v = vct(cur.mask);
        int x = cur.x, y = cur.y;
        int turns = mp[cur.x][cur.y][cur.mask];
        vector<vector<char> > vis = VIS;
        q.pop();
        int cx = x, cy = y;
        vis[cx][cy] = 1;
        for (int i = 0; i < v.size(); i++) {
            cx = cx + dx[v[i]];
            cy = cy + dy[v[i]];
            vis[cx][cy] = i+2;
        }
        
        vector<int> V = v;
        for (int j = (int)V.size() - 1; j > 0; j--)
                V[j] = V[j-1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (vis[nx][ny] == 0 || vis[nx][ny] == mx)) {
                V[0] = i^1;
                state nxt;
                nxt.mask = Mask(V);
                nxt.x = nx; nxt.y = ny;
                if (!mp[nxt.x][nxt.y][nxt.mask]) {
                    q.push(nxt);
                    mp[nxt.x][nxt.y][nxt.mask] = turns+1;
                    if (make_pair(nx, ny) == dest) {
                        ans = min(ans, turns);
                    }
                }
            }
        }
    }

    if (ans == 1000000) ans = -1;
    cout << ans;

    return 0;
}