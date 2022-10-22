#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<int> dep, subtr;
int binLift[100001][20];

void dfs(int n, int par = -1) {
    for(int ch : adj[n]) {
        if(ch == par) continue;
        dep[ch] = dep[n] + 1;
        dfs(ch, n);
        binLift[ch][0] = n;
        subtr[n] += subtr[ch];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n);
    dep.resize(n, 0);
    subtr.resize(n, 1);
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    binLift[0][0] = -1;
    for(int i = 1; i < 20; i++) {
        for(int x = 0; x < n; x++) {
            int y = binLift[x][i-1];
            if(y == -1) binLift[x][i] = -1;
            else binLift[x][i] = binLift[y][i-1];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(dep[x] > dep[y]) swap(x, y);
        int X = x, Y = y;
        if(x == y) {
            cout << n << '\n';
            continue;
        }
        if((dep[y] - dep[x]) % 2) {
            cout << "0\n";
            continue;
        }
        int len = dep[y] - dep[x];
        for(int i = 19; i >= 0; i--) {
            if(len & (1 << i)) {
                y = binLift[y][i];
            }
        }
        for(int i = 19; i >= 0; i--) {
            if((1 << i) > dep[x]) continue;
            if(binLift[x][i] != binLift[y][i]) {
                x = binLift[x][i];
                y = binLift[y][i];
                len += (2 << i);
            }
        }
        int lca;
        if(x == y) {
            lca = x;
        }
        else {
            lca = binLift[x][0];
            len += 2;
        }
        assert(!(len%2));
        int midpt = Y;
        for(int i = 19; i >= 0; i--) {
            if((2 << i) & len) {
                midpt = binLift[midpt][i];
            }
        }
        if(midpt == lca) {
            cout << n - subtr[x] - subtr[y] << '\n';
        }
        else {
            y = Y;
            len = (len/2 - 1);
            for(int i = 19; i >= 0; i--) {
                if((1 << i) & len) y = binLift[y][i];
            }
            cout << subtr[midpt] - subtr[y] << '\n';
        }
    }
}