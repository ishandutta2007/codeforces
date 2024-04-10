// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct red {
    vector<int> v;
    int id;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<red> a(2*n);
        for (int i=0; i<2*n; i++) {
            auto& b = a[i].v;
            a[i].id = i;
            b.resize(n);
            for (int j=0; j<n; j++) {
                cin >> b[j];
                b[j]--;
            }
        }

        vector<int> fixed;
        while (1) {
            bool found = false;
            for (int col=0; col<n; col++) {
                vector<int> freq(n), pos(n);
                for (int row=0; row<(int)a.size(); row++) {
                    int x = a[row].v[col];
                    freq[x]++;
                    pos[x] = row;
                }

                for (int x=0; x<n; x++) {
                    if (freq[x] == 1) {
                        int row = pos[x];
                        fixed.push_back(a[row].id);
                        vector<int> trem;
                        for (int i=(int)a.size()-1; i>=0; i--) {
                            for (int j=0; j<n; j++) {
                                if (a[row].v[j] == a[i].v[j]) {
                                    trem.push_back(i);
                                    break;
                                }
                            }
                        }
                        for (int i : trem) {
                            swap(a.back(), a[i]);
                            a.pop_back();
                        }

                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                break;
            }
        }

        const int m = a.size();
        string vis(m, 0);
        vector<vector<int>> e(m);
        for (int j=0; j<n; j++) {
            vector<pair<int, int>> b(n, {-1, -1});
            for (int i=0; i<m; i++) {
                int x = a[i].v[j];
                if (b[x].first == -1) {
                    b[x].first = i;
                } else {
                    b[x].second = i;
                }
            }
            for (auto [x, y] : b) {
                if (x != -1) {
                    e[x].push_back(y);
                    e[y].push_back(x);
                }
            }
        }

        int mult = 1;
        vector<int> dist(m, -1);
        for (int i=0; i<m; i++) {
            if (dist[i] == -1) {
                mult = (2 * mult) % 998'244'353;
                dist[i] = 0;
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int x = q.front(); q.pop();
                    for (int y : e[x]) {
                        if (dist[y] == -1) {
                            dist[y] = dist[x] + 1;
                            q.push(y);
                        }
                    }
                }
            }
        }

        for (int i=0; i<m; i++) {
            if (dist[i] % 2 == 0) {
                fixed.push_back(a[i].id);
            }
        }

        cout << mult << '\n';
        for (int x : fixed) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}