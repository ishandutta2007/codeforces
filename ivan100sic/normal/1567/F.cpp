// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

// distance from edges (num X) + row num // parity 
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
string s[505];
int dist[505][505], sol[505][505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> s[i];

    for (int i=1; i<n-1; i++) {
        for (int j=1; j<m-1; j++) {
            if (s[i][j] == 'X') {
                int c = 0;
                c += s[i-1][j] == '.';
                c += s[i+1][j] == '.';
                c += s[i][j-1] == '.';
                c += s[i][j+1] == '.';
                if (c % 2 == 1) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    memset(dist, 255, sizeof(dist));

    deque<pair<int, int>> q;
    dist[0][0] = 0;
    q.push_back({0, 0});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int d=0; d<8; d++) {
            int u = x + dx[d];
            int v = y + dy[d];
            if (u < 0 || v < 0 || u >= n || v >= m) continue;
            if (abs(dx[d]) + abs(dy[d]) == 2 && (s[u][v] == 'X' || s[x][y] == 'X')) {
                continue;
            }
            
            if (dist[u][v] == -1) {
                if (s[u][v] == 'X') {
                    dist[u][v] = dist[x][y] + 1;
                    q.push_back({u, v});
                } else {
                    dist[u][v] = dist[x][y];
                    q.push_front({u, v});
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == '.') {
                sol[i][j] = ((i + dist[i][j]) % 2) * 3 + 1;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == 'X') {
                int c = 0;
                c += sol[i-1][j] * (s[i-1][j] == '.'); 
                c += sol[i+1][j] * (s[i+1][j] == '.'); 
                c += sol[i][j-1] * (s[i][j-1] == '.'); 
                c += sol[i][j+1] * (s[i][j+1] == '.');
                sol[i][j] = c;
            }
        }
    }

    cout << "YES\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << sol[i][j] << " \n"[j == m-1];
        }
    }
}