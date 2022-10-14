#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 605;

int n, m;
int cost[MAXN][MAXN * 2];
int dist[MAXN][MAXN], bio[MAXN];

void precompute () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = min(cost[i][j], cost[i][j + n]);
            cost[i][j + n] = cost[i][j];
        }
    }
}

void dijkstra (int poc) {
    for (int i = 0; i < n; i++) {
        dist[poc][i] = 2e9;
        bio[i] = 0;
    }
    dist[poc][poc] = 0;
    for (int br = 0; br < n; br++) {
        int ind = -1, mn = 2e9;
        for (int i = 0; i < n; i++) {
            if (!bio[i] && dist[poc][i] < mn) {
                mn = dist[poc][i];
                ind = i;
            }
        }
        bio[ind] = 1;
        int ofs = (n - dist[poc][ind] % n) % n;
        for (int i = 0; i < n; i++) {
            dist[poc][i] = min(dist[poc][i], dist[poc][ind] + cost[ind][i + ofs]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            cost[i][j] = 2e9;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < n; j++) {
            cost[a][b + j] = min(cost[a][b + j], c + j);
        }
    }
    precompute();
    for (int i = 0; i < n; i++) dijkstra(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}