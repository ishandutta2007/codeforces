#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n, k;
vector<vector<int>> v;
vector<vector<pair<long long, long long>>> w;

long long res(int u, int d) {
    long long ans = 0;
    for (int i : v[u]) {
        if (i != d) {
            ans += res(i, u);
        }
    }
    queue<vector<pair<long long, long long>>> q;
    for (int i : v[u]) {
        if (i != d) {
            vector<pair<long long, long long>> temp(k);
            for (int j = 1; j < k; ++j) {
                temp[j].second = w[i][j - 1].second;
                temp[j].first += w[i][j - 1].first;
            }
            if (k != 1) {
                ++temp[1].first;
            } else {
                ++temp[0].first;
                ++temp[0].second;
            }
            temp[0].second += w[i][k - 1].second + w[i][k - 1].first;
            temp[0].first += w[i][k - 1].first;
            for (int j = 0; j < k; ++j) {
                w[u][j].first += temp[j].first;
                w[u][j].second += temp[j].second;
            }
            q.push(temp);
        }
    }
    for (int i : v[u]) {
        if (i != d) {
            auto temp = q.front();
            q.pop();
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l < k; ++l) {
                    ans += 2 * temp[j].second * (w[u][l].first - temp[l].first);
                    if (j + l > 0) {
                        ans += temp[j].first *
                               (w[u][l].first - temp[l].first);
                    }
                    if (j + l > k) {
                        ans += temp[j].first *
                               (w[u][l].first - temp[l].first);
                    }
                }
            }
        }
    }
    ans -= 2 * w[u][0].first;
    for (int j = 0; j < k; ++j) {
        ans += 2 * w[u][j].second;
        ans += 2 * w[u][j].first;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    v.resize(n);
    w.resize(n, vector<pair<long long, long long>>(k,
                                                   pair<long long, long long>(0,
                                                                              0)));
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        v[--a].push_back(--b);
        v[b].push_back(a);
    }
    cout << res(0, -1) / 2;
    return 0;
}