#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<bool> blocked;
vector<int> ran;
vector<int> sub;
vector<vector<int>> adj;

bool mark_centroid(int x, int siz, int ra = 0, int par = -1) {
    if(x == -1) return false;
    if(siz == 1) {
        ran[x] = ra;
        blocked[x] = true;
        return true;
    }
    bool ok = true;
    sub[x] = 1;
    int sum = siz - 1;
    for(int ch : adj[x]) {
        if(blocked[ch] || par == ch) continue;
        if(mark_centroid(ch, siz, ra, x)) return true;
        if(2 * sub[ch] > siz) ok = false;
        sum -= sub[ch];
        sub[x] += sub[ch];
    }
    if(ok && (2 * sum <= siz)) {
        blocked[x] = true;
        ran[x] = ra;
        mark_centroid(par, sum, ra+1);
        for(int ch : adj[x]) {
            if(blocked[ch] || par == ch) continue;
            mark_centroid(ch, sub[ch], ra+1);
        }
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    blocked.resize(n);
    ran.resize(n);
    adj.resize(n);
    sub.resize(n);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    mark_centroid(0, n);
    for(int i = 0; i < n; i++) {
        cout << (char)('A' + ran[i]) << ' ';
    }
    cout << '\n';
}