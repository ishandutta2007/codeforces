#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

int n, k;


int mas = 0;

vector<pair<int, int>> ans(1000000);
void solve(vector<vector<int>> poses) {
    vector<int> all;
    for (int i = 0; i < poses.size(); i++) {
        for (int j = 0; j < k; j++) {
            all.push_back(poses[i][j]);
        }
    }
    sort(all.begin(), all.end());
    map<int, int> conv;
    for (int i = 0; i < all.size(); i++) {
        conv[all[i]] = i;
    }
    int len = all.size();
    for (int i = 0; i < poses.size(); i++) {
        for (int j = 0; j < k; j++) {
            poses[i][j] = conv[poses[i][j]];
        }
    }
    vector<int> start(poses.size());
    vector<bool> used(poses.size());
    for (int _ = 0; _ < poses.size(); _++) {

        int val = 1000000;
        int ind = -1;
        for (int i = 0; i < poses.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (poses[i][start[i] + 1] < val) {
                val = poses[i][start[i] + 1];
                ind = i;
            }
        }
        ans[mas + ind].first = all[poses[ind][start[ind]]] + 1;
        ans[mas + ind].second = all[poses[ind][start[ind] + 1]] + 1;
        used[ind] = true;
        for (int i = 0; i < poses.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (poses[i][start[i]] < poses[ind][start[ind] + 1]) {
                start[i]++;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<vector<int>> poses(n);
    for (int i = 0; i < n * k; i++) {
        int c;
        cin >> c;
        poses[c - 1].push_back(i);
    }
    for (int i = 0; i < n; i += k - 1) {
        vector<vector<int>> kek;
        for (int j = i; j < min(i + k - 1, n); j++) {
            kek.push_back(poses[j]);
        }
        mas = i;
        solve(kek);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}