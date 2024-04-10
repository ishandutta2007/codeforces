#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;

int n, m, sol = 1e9;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int mx[MAXN * MAXN];
vector <pi> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v.push_back({c[j] - a[i] + 1, d[j] - b[i] + 1});
        }
    }
    sort(v.begin(), v.end());
    for (int i = (int) v.size() - 1; i >= 0; i--) {
        mx[i] = max(mx[i + 1], v[i].second);
    }
    sol = mx[0];
    for (int i = 0; i < v.size(); i++) {
        sol = min(sol, max(v[i].first, 0) + mx[i + 1]);
    }
    cout << sol;
    return 0;
}