#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 5005;

ll x[N], y[N];

bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> ans;
    ans.push_back(1);
    vis[1] = 1;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    int now = 1;
    for (int i = 1; i < n; i++) {
        int dian;
        ll dis = 0;
        for (int j = 1; j <= n; j++) {
            if (now == j || vis[j]) continue;
            ll d = (x[now] - x[j]) * (x[now] - x[j]) + (y[now] - y[j]) * (y[now] - y[j]);
            if (d > dis) {
                dis = d;
                dian = j;
            }
        }
        ans.push_back(dian);
        vis[dian] = 1;
        now = dian;
    }
    for (auto x:ans) cout << x << ' ';
}