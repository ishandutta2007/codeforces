#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    vector<string> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
        v[i] += "....";
    }

    int m4   = 0b1111'1111'1111;
    int m3_u = 0b1110'1110'1110;
    int m3_d = 0b0111'0111'0111;
    int m2_u = 0b1100'1100'0000;
    int m2_m = 0b0110'0110'0000;
    int m2_d = 0b0011'0011'0000;
    int m1_u = 0b1000'0000'0000;
    int m1_m = 0b0100'0000'0000;
    int m1_M = 0b0010'0000'0000;
    int m1_d = 0b0001'0000'0000;

    vector<vector<pair<int, int>>> poss = {
        {{m3_u, a3}, {m2_u, a2}, {m1_u, a1}, {0, 0}}, 
        {{m3_d, a3}, {m2_m, a2}, {m1_m, a1}, {0, 0}}, 
        {{m2_d, a2}, {m1_M, a1}, {0, 0}}, 
        {{m1_d, a1}, {0, 0}}
    };

    using DP = array<int, 1 << 12>;
    DP dp;
    dp.fill(numeric_limits<int>::max() / 2);
    dp[0] = 0;
    for (int i = 0; i < n + 4; i++) {
        int mask_cur = 0;
        for (int j = 0; j < 4; j++) {
            mask_cur = mask_cur * 2 + (v[j][i] == '*');
        }

        DP dp2;
        dp2.fill(numeric_limits<int>::max() / 2);
        for (int mask = 0; mask < (1 << 12); mask++) {
            if (dp[mask] == numeric_limits<int>::max() / 2)
                continue;
            dp2[0] = min(dp2[0], dp[mask] + a4);
            
            for (auto p1 : poss[0]) {
                int mm = mask ^ (mask & p1.first);
                if (mm & m1_u) continue;
                int sum = p1.second;

                for (auto p2 : poss[1]) {
                    int MM = mm ^ (mm & p2.first);
                    if (MM & m1_m) continue;
                    int sum2 = sum + p2.second;

                    for (auto p3 : poss[2]) {
                        int NN = MM ^ (MM & p3.first);
                        if (NN & m1_M) continue;
                        int sum3 = sum2 + p3.second;

                        for (auto p4 : poss[3]) {
                            int OO = NN ^ (NN & p4.first);
                            if (OO & m1_d) continue;
                            int sum4 = sum3 + p4.second;
                            int neww = ((OO << 4) & m4) | mask_cur;
                            dp2[neww] = min(dp2[neww], dp[mask] + sum4);
                        }
                    }
                }
            }
        }
        dp.swap(dp2);
    }
    cout << dp[0] << endl;
}