#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<int> go;

int get(int x) {
    if (go[x] == x || go[x] == -1) {
        return go[x];
    }
    return go[x] = get(go[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    go.resize(m);
    iota(go.begin(), go.end(), 0);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> b(k);
        for (int j = 0; j < k; j++) {
            cin >> b[j];
            b[j]--;
        }
        while ((int) b.size()) {
            int x = b[0], y = get(b[0]);
            if (y == -1) {
                b.erase(b.begin());
                continue;
            } else {
                if ((int) b.size() >= 2 && get(b[1]) == y) {
                    break;
                }
                int res = -1;
                if ((int) b.size() >= 2) {
                    res = b[1];
                }
                go[y] = res;
                ans.push_back(i);
                break;
            }
        }
    }
    int answer = 1;
    for (int i = 0; i < (int) ans.size(); i++) {
        answer = answer * 2ll % mod;
    }
    cout << answer << " " << (int) ans.size() << '\n';
    for (auto i : ans) {
        cout << i + 1 << " ";
    }
}