#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<vector<ll>> nums, pre1, pre2, pre3, pre4;

ll p1(int i, int j) {
    if(i == 0 && j == 0) return 0;
    else if(i == 0) return pre1[i][j-1];
    else if(j == 0) return pre1[i-1][j];
    else return max(pre1[i-1][j], pre1[i][j-1]);
}

ll p2(int i, int j) {
    int x = 0, y = nums[0].size()-1;
    if(i == x && j == y) return 0;
    else if(i == x) return pre2[i][j+1];
    else if(j == y) return pre2[i-1][j];
    else return max(pre2[i-1][j], pre2[i][j+1]);
}

ll p3(int i, int j) {
    int x = nums.size()-1, y = 0;
    if(i == x && j == y) return 0;
    else if(i == x) return pre3[i][j-1];
    else if(j == y) return pre3[i+1][j];
    else return max(pre3[i+1][j], pre3[i][j-1]);
}

ll p4(int i, int j) {
    int x = nums.size()-1, y = nums[0].size()-1;
    if(i == x && j == y) return 0;
    else if(i == x) return pre4[i][j+1];
    else if(j == y) return pre4[i+1][j];
    else return max(pre4[i+1][j], pre4[i][j+1]);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t, m, n;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> m >> n;
    nums.resize(m);
    pre1.resize(m);
    pre2.resize(m);
    pre3.resize(m);
    pre4.resize(m);
    for(int i = 0; i < m; i++) {
        nums[i].resize(n);
        pre1[i].resize(n);
        pre2[i].resize(n);
        pre3[i].resize(n);
        pre4[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    // cout << "Bryce orz\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            pre1[i][j] = nums[i][j] + p1(i, j);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = n-1; j >= 0; j--) {
            pre2[i][j] = nums[i][j] + p2(i, j);
        }
    }
    for(int i = m-1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            pre3[i][j] = nums[i][j] + p3(i, j);
        }
    }
    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            pre4[i][j] = nums[i][j] + p4(i, j);
        }
    }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << pre1[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << pre2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << pre3[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << pre4[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i < m-1; i++) {
        for(int j = 1; j < n-1; j++) {
            ans = max(ans, max(pre1[i-1][j] + pre2[i][j+1] + pre3[i][j-1] + pre4[i+1][j], pre1[i][j-1] + pre2[i-1][j] + pre3[i+1][j] + pre4[i][j+1]));
        }
    }
    cout << ans << '\n';
}