#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int> > g[300000];
int color[300000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(pair<int, int>(b, i));
        g[b].push_back(pair<int, int>(a, i));
    }
    memset(color, -1, sizeof color);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1 && color[g[i][0].second] == -1) {
            color[g[i][0].second] = cnt++;
        }
    }
    for (int i = 1; i < n; i++) {
        if (color[i] == -1) color[i] = cnt++;
        cout << color[i] << endl;
    }
}