#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string.h>
#include <string>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 1111;
bool canrow[N], cancol[N];
bool used[N][N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);


    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) {
        canrow[i] = cancol[i] = true;
    }
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        canrow[a] = 0;
        cancol[b] = 0;
        used[a][b] = 1;
    }

    int ans = 0;
    for (int i = 2; i < n - i + 1; ++i) {
        vector<int> bad;
        
        int r1 = i, r2 = n - i + 1;
        int c1 = i, c2 = n - i + 1;

        if (!canrow[r1]) { 
            bad.push_back(1);
            bad.push_back(2);
        }
        if (!canrow[r2]) {
            bad.push_back(4);
            bad.push_back(8);
        }
        if (!cancol[c1]) { 
            bad.push_back(16);
            bad.push_back(32);
        }
        if (!cancol[c2]) {
            bad.push_back(64);
            bad.push_back(128);
        }
        bad.push_back((1 << 0) + (1 << 1));
        bad.push_back((1 << 2) + (1 << 3));
        bad.push_back((1 << 4) + (1 << 5));
        bad.push_back((1 << 6) + (1 << 7));

        bad.push_back((1 << 0) + (1 << 4));
        bad.push_back((1 << 0) + (1 << 7));

        bad.push_back((1 << 1) + (1 << 6));
        bad.push_back((1 << 1) + (1 << 5));

        bad.push_back((1 << 2) + (1 << 5));
        bad.push_back((1 << 2) + (1 << 6));

        bad.push_back((1 << 3) + (1 << 7));
        bad.push_back((1 << 3) + (1 << 4));

        int cand = 0;
        for (int msk = 0; msk < 255; ++msk) {
            bool cool = true;
            for (int j = 0; j < bad.size(); ++j)
                if ((msk & bad[j]) == bad[j]) {
                    cool = false;
                    break;
                }
            if (cool) {
                int res = 0;
                for (int j = 0; j < 8; ++j)
                    if (msk & (1 << j)) {
                        ++res;
                    }
                cand = max(cand, res);
            }
        }
        ans += cand;
    }

    if ((n & 1) && n > 1) {
        if (canrow[(n + 1) / 2] || cancol[(n + 1) / 2]) ++ans;
    }

    cout << ans << endl;

    return 0;
}