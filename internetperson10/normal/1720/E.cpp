#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int nums[501][501];
int mi[250001][2], ma[250001][2];
int pref[501][501];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> s;
    for(int i = 0; i <= n*n; i++) {
        for(int j = 0; j < 2; j++) {
            mi[i][j] = 999999;
            ma[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            s.insert(x);
            nums[i][j] = x;
            mi[x][0] = min(mi[x][0], i);
            mi[x][1] = min(mi[x][1], j);
            ma[x][0] = max(ma[x][0], i);
            ma[x][1] = max(ma[x][1], j);
        }
    }
    if(s.size() <= k) {
        cout << k - s.size() << '\n';
        return 0;
    }
    int m = s.size();
    for(int g : s) v.push_back(g);
    bool ok = false;
    for(int z = 1; z <= n; z++) {
        for(int g : v) {
            int lx = max(0, ma[g][0] - z + 1);
            int ly = max(0, ma[g][1] - z + 1);
            int rx = min(n-z+1, mi[g][0] + 1);
            int ry = min(n-z+1, mi[g][1] + 1);
            if(lx >= rx || ly > ry) continue;
            pref[lx][ly]++;
            pref[lx][ry]--;
            pref[rx][ly]--;
            pref[rx][ry]++;
        }
        for(int j = 1; j <= n; j++) {
            pref[0][j] += pref[0][j-1];
        }
        for(int i = 1; i <= n; i++) {
            pref[i][0] += pref[i-1][0];
            for(int j = 1; j <= n; j++) {
                pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i < n && j < n && (pref[i][j] == m-k || pref[i][j] == m-k+1)) ok = true;
                pref[i][j] = 0;
            }
        }
    }
    if(ok) cout << 1 << '\n';
    else cout << 2 << '\n';
}