#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pair<int, int>> compressed;
    for (int i = 0; i < n; i++) {
        if (i == 0 || compressed.back().first != v[i]) {
            compressed.push_back({v[i], 1});
        } else {
            compressed.back().second++;
        }
    }
    auto& c = compressed;
    int s = c.size();

    vector<int> psum_ones;
    psum_ones.push_back(0);
    for (int i = 0; i < s; i++) {
        psum_ones.push_back(psum_ones.back() + (c[i].first == 1 ? c[i].second : 0));
    }
    vector<int> psum_twos;
    psum_twos.push_back(0);
    for (int i = 0; i < s; i++) {
        psum_twos.push_back(psum_twos.back() + (c[i].first == 2 ? c[i].second : 0));
    }

    // auto comp = [&psum_ones,&psum_twos](int i, int j, int k) {
    //     int x = 0;
    // }
    
    // first compute best  without switch
    int m = 0;
    for (int i = 0; i <= s; i++) {
        m = max(m, psum_ones[i] + psum_twos[s] - psum_twos[i]);
    }

    vector<vector<vector<int>>> dp(s, vector<vector<int>>(s, vector<int>(3, 0)));
    for (int i = 0; i < s; i++) {
        if (c[i].first == 1) {
            dp[i][i][1] = c[i].second;
            dp[i][i][2] = 0;
        } else {
            dp[i][i][1] = c[i].second;
            dp[i][i][2] = c[i].second;
        }

        for (int j = i + 1; j < s; j++) {
            if (c[j].first == 1) {
                dp[i][j][1] = c[j].second + max(dp[i][j-1][1], dp[i][j-1][2]);
                dp[i][j][2] = dp[i][j-1][2];
            } else {
                dp[i][j][1] = max(dp[i][j-1][1], dp[i][j-1][2] + c[j].second);
                dp[i][j][2] = dp[i][j-1][2] + c[j].second;
            }
        }
    }

    for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
            // switch i to j
            // point has to be inside [i, j]
            int t = psum_ones[i] + psum_twos[s] - psum_twos[j+1];
            t += dp[i][j][1];
            m = max(m, t);
        }
    }

    cout << m << endl;
}