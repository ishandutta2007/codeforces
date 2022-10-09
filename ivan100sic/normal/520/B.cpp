#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int d[100005];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    fill(d, d+100005, 123123123);
    d[x] = 0;
    while (q.size()) {
        int x = q.front(); q.pop();
        if (x >= 1 && d[x-1] == 123123123) {
            d[x-1] = d[x] + 1;
            q.push(x-1);
        }

        if (2*x < 100005 && d[2*x] == 123123123) {
            d[2*x] = d[x] + 1;
            q.push(2*x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int u, v;
    cin >> u >> v;
    bfs(u);
    cout << d[v] << '\n';
}