#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int w[MAXN], deg[MAXN];
vector <pi> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n;
        llint sol = 0;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            sol += w[i];
            deg[i] = -1;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            deg[a]++; deg[b]++;
        }
        for (int i = 1; i <= n; i++) {
            v.push_back({-w[i], deg[i]});
        }
        sort(v.begin(), v.end());
        cout << sol << " ";
        for (auto pp : v) {
            int val = -pp.first;
            int br = pp.second;
            for (int i = 0; i < br; i++) {
                sol += val;
                cout << sol << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}