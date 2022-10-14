#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

int n, sx, sy;
int x[MAXN], y[MAXN];
int cnt[4];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> sx >> sy;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (y[i] > sy) cnt[0]++;
        if (x[i] > sx) cnt[1]++;
        if (y[i] < sy) cnt[2]++;
        if (x[i] < sx) cnt[3]++;
    }
    int mx = -1, ind = -1;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            ind = i;
        }
    }
    cout << mx << endl;
    cout << sx + dx[ind] << " " << sy + dy[ind];
    return 0;
}