#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, m;
int cnt[MAXN], sol[MAXN];
vector <int> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= m; i++) {
            v[i].clear();
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int x; cin >> x;
                v[i].push_back(x);
            }
            cnt[v[i][0]]++;
            sol[i] = v[i][0];
        }
        int mx = 0, ind = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > mx) mx = cnt[i], ind = i;
        }
        for (int i = 1; i <= m; i++) {
            if (mx <= (m + 1) / 2) break;
            if (v[i].size() > 1 && v[i][0] == ind) sol[i] = v[i][1], mx--;
        }
        if (mx <= (m + 1) / 2) {
            cout << "YES\n";
            for (int i = 1; i <= m; i++) cout << sol[i] << " ";
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}