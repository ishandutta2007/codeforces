#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int q, n;
int a[MAXN], lef[MAXN], rig[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            lef[i] = rig[i] = -1;
        }
        v.clear();
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            v.push_back(a[i]);
            if (lef[a[i]] == -1) lef[a[i]] = i;
            rig[a[i]] = i;
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int cnt = 1, mx = 0;
        for (int i=0; i<v.size(); i++) {
            if (i == v.size() - 1 || lef[v[i+1]] < rig[v[i]]) {
                mx = max(mx, cnt);
                cnt = 0;
            }
            cnt++;
        }
        cout << v.size() - mx << '\n';
    }
    return 0;
}