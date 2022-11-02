#include <bits/stdc++.h>

using namespace std;

const int N = 1000043;
int q;
char buf[N];
int n, k;

int ceilLog(int x) {
    int y = 0;
    while ((1 << y) < x) y++;
    return y;
}

int main() {
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &n, &k);
        scanf("%s", buf);
        string s = buf;
        int m = min(k, ceilLog(n - k + 2));
        vector<int> used(1 << m, 0);
        vector<int> next0(n, int(1e9));
        if (s[n - 1] == '0') next0[n - 1] = n - 1;
        for (int j = n - 2; j >= 0; j--) {
            next0[j] = s[j] == '0' ? j : next0[j + 1];
        }
        int d = k - m;
        for (int j = 0; j < n - k + 1; j++) {
            if (next0[j] - j < d) continue;
            int cur = 0;
            for (int x = j + d; x < j + k; x++) cur = cur * 2 + (s[x] - '0');
            used[((1 << m) - 1) ^ cur] = 1;
        }
        int ans = -1;
        for (int j = 0; j < (1 << m); j++) {
            if (used[j] == 0) {
                ans = j;
                break;
            }
        }
        if (ans == -1) {
            puts("NO");
        } else {
            puts("YES");
            string res(d, '0');
            string res2;
            for (int j = 0; j < m; j++) {
                res2.push_back('0' + (ans % 2));
                ans /= 2;
            }
            reverse(res2.begin(), res2.end());
            res += res2;
            puts(res.c_str());
        }
    }
}