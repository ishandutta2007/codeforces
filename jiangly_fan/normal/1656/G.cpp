#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1), c(n + 1);
        map<int, int> mp;
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            mp[a[i]] += 1;
        }
        int odd = 0;
        for (auto [x, y] : mp)
            if (y & 1) {
                if (odd) {
                    odd = -1;
                    break;
                }
                else odd = x;   
            }
        if (odd == -1) {
            cout << "NO\n";
            continue;
        }
        int k = 0;
        for (int i = 1; i <= n; i += 1)
            if (a[i] == odd and i != (n + 1) / 2)
                k = i;
        if (n % 2 and not k) {
            cout << "NO\n";
            continue;
        }
        map<int, int> f;
        if (n % 2) b[k] = 1;
        for (int i = 1, c = n % 2; i <= n; i += 1) if (i != k) {
            if (not f.contains(a[i])) b[i] = f[a[i]] = c += 1;
            else {
                b[i] = f[a[i]];
                f.erase(a[i]);
            }
        }
        vector<vector<int>> G(n + 1), p(n + 1);
        for (int i = 1; i <= n; i += 1) {
            //cout << b[i] << " ";
            p[b[i]].push_back(i);
        }
        //cout << "\n";
        for (int i = 1; i <= n; i += 1) {
            if (n % 2 == 0 or i != (n + 1) / 2)
                G[i].push_back(n + 1 - i);
            if(p[i].size() == 2) {
                G[p[i][0]].push_back(p[i][1]);
                G[p[i][1]].push_back(p[i][0]);
            }
        }
        if (n & 1) {
            G[(n + 1) / 2].push_back(k);
            G[k].push_back((n + 1) / 2);
        }
        vector<int> res(n + 1);
        vector<vector<int>> cyc;
        auto findc = [&](int i) {
            vector<int> v;
            int j = i, p = 0;
            while (true) {
                v.push_back(j);
                int nj = 0;
                for (int k : G[j]) if (k != p) nj = k;
                if (not nj) nj = p;
                res[j] = nj;
                if (not res[nj]) {
                    p = j;
                    j = nj;
                }
                else break;
            }
            cyc.push_back(v);
        };
        if (n & 1) findc((n + 1) / 2);
        for (int i = 1; i <= n; i += 1) if (not res[i]) findc(i);
        //for (int i = 1; i <= n; i += 1) cout << res[i] << " "; cout << "\n";
        //for (int i = 1; i <= n; i += 1) cout << b[res[i]] << " "; cout << "\n";
        vector<pair<int, int>> vp;
        for (auto c : cyc) {
            for (int i = 1; i < c.size(); i += 1)
                if (c[i] + c[i - 1] == n + 1) {
                    vp.emplace_back(c[i], c[i - 1]);
                    break;
                }
        }
        for (int i = 1; i < vp.size(); i += 1) {
            auto [a, b] = vp[i - 1];
            auto [c, d] = vp[i];
            swap(res[a], res[c]);
            swap(res[b], res[d]);
            swap(res[a], res[b]);
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i += 1) cout << res[i] << " "; cout << "\n";
        //for (int i = 1; i <= n; i += 1) cout << b[res[i]] << " "; cout << "\n";
    }
    return 0;
}