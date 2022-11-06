#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> cnt(201, 0);

    vector< pair<int, int> > data(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> data[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> data[i].second;
        cnt[data[i].second]++;
    }
    sort(data.begin(), data.end());

    vector< vector<int> > groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || data[i].first != data[i - 1].first) {
            groups.push_back(vector<int>());
        }
        groups[groups.size() - 1].push_back(data[i].second);
    }
    reverse(groups.begin(), groups.end());

    int result = 1e8;
    int S = 0;
    int rest = n;
    for (auto &i: groups) {
        for (auto j: i) {
            cnt[j]--;
        }
        int k = rest - 2 * (int) i.size() + 1;
        int t = S;
        for (int j = 1; j <= 200 && k > 0; j++) {
            t += min(cnt[j], k) * j;
            k -= min(cnt[j], k);
        }
        result = min(result, t);
        for (auto j: i) {
            S += j;
        }
        rest -= i.size();
    }

    cout << result << endl;
}