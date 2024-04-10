#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

const int maxn = 1 << 17;

int x[maxn], p[maxn];

bool cmp(int i, int j) {
    return x[i] < x[j];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    while (cin >> n) {
        for (int i = 1; i <= 9; i++) cin >> x[i], p[i] = i;
        sort(p + 1, p + 10, cmp);

        vector<int> ans;
        while (n >= x[p[1]]) {
            ans.push_back(p[1]);
            n -= x[p[1]];
        }
        for (int i = 0; i < ans.size(); i++) {
            int mx = 1;
            for (int j = 1; j <= 9; j++) {
                if (n >= x[p[j]] - x[p[1]] && p[j] > p[mx]) {
                    mx = j;
                }
            }
            n -= x[p[mx]] - x[p[1]];
            ans[i] = p[mx];
        }
        if (ans.empty()) cout << -1;
        for (int i = 0; i < ans.size(); i++) cout << ans[i];
        cout << endl;
    }

    return 0;
}