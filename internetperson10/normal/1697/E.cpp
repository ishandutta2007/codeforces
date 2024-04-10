#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

vector<vector<int>> adj;
vector<pair<int, int>> points;

int dist(int i, int j) {
    return abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
}

vector<int> v;
int ct[5];
ll ans[101][201];

void rec(int x, int i) {
    int val = 0;
    if(i == 2) {
        if(adj[v[0]] == vector<int>{v[1]}) val++;
        if(adj[v[1]] == vector<int>{v[0]}) val++;
        if(val == 2) ct[2]++;
    }
    if(i == 3) {
        if(adj[v[0]] == vector<int>{v[1], v[2]}) val++;
        if(adj[v[1]] == vector<int>{v[0], v[2]}) val++;
        if(adj[v[2]] == vector<int>{v[0], v[1]}) val++;
        if(val == 3) ct[3]++;
    }
    if(i == 4) {
        if(adj[v[0]] == vector<int>{v[1], v[2], v[3]}) val++;
        if(adj[v[1]] == vector<int>{v[0], v[2], v[3]}) val++;
        if(adj[v[2]] == vector<int>{v[0], v[1], v[3]}) val++;
        if(adj[v[3]] == vector<int>{v[0], v[1], v[2]}) val++;
        if(val == 4) ct[4]++;
        return;
    }
    for(int y = x+1; y < points.size(); y++) {
        v.push_back(y);
        rec(y, i+1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    points.resize(n);
    adj.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    for(int i = 0; i < n; i++) {
        int bestDist = 1e9;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            bestDist = min(bestDist, dist(i, j));
        }
        for(int j = 0; j < n; j++) {
            if(dist(i, j) == bestDist) {
                adj[i].push_back(j);
            }
        }
    }
    rec(-1, 0);
    ans[0][n] = 1;
    v.push_back(0);
    int tot = n;
    for(int i = 4; i > 1; i--) {
        while(ct[i]--) {
            tot -= i;
            v.push_back(i);
        }
    }
    while(tot--) {
        v.push_back(1);
    }
    ll totAns = 0;
    for(int i = 1; i < v.size(); i++) {
        for(int j = 0; j <= n; j++) {
            ll tot = 1;
            for(int k = j+1; k <= j+v[i]; k++) {
                tot *= k;
            }
            ans[i][j] += (ans[i-1][j+v[i]] * tot);
            ans[i][j] %= MOD;
            if(v[i] > 1) {
                ans[i][j] += (ans[i-1][j+1] * (j+1));
                ans[i][j] %= MOD;
            }
            if(i == v.size() - 1) {
                totAns += ans[i][j];
                totAns %= MOD;
            }
        }
    }
    cout << totAns << '\n';
}