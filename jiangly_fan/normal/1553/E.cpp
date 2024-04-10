#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int q;
    for (cin >> q; q; q -= 1) {
        int n, m;
        cin >> n >> m;
        vector<int> p(n), ms(n);
        for (int i = 0; i < n; i += 1){
            cin >> p[i];
            p[i] -= 1;
            ms[(i - p[i] + n) % n] += 1;
        }
        vector<int> ans;
        for (int k = 0; k < n; k += 1)
            if ((n - ms[k] + 1) / 2 <= m) {
                //cout << "k = " << k << "\n";
                vector<int> vis(n);
                int res = n;
                for (int i = 0; i < n; i += 1) if (not vis[i]) {
                    res -= 1;
                    for (int x = i; not vis[x]; x = (p[x] + k) % n)
                        vis[x] = 1;
                }
                if (res <= m) ans.push_back(k);
            }
        cout << ans.size();
        for (int k : ans) cout << " " << k;
        cout << "\n";
    }
    return 0;
}