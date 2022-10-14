#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n;
int x[MAXN], y[MAXN];
pi p[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (i > 0) p[i] = {x[i] - x[i - 1], y[i] - y[i - 1]};
    }
    p[0] = {x[0] - x[n-1], y[0] - y[n-1]};
    if (n % 2 == 1) {
        cout << "NO";
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int nxt = (i + n/2) % n;
        if (p[i].first == -p[nxt].first && p[i].second == -p[nxt].second) cnt++;
    }
    if (cnt == n) cout << "YES"; else cout << "NO";
    return 0;
}