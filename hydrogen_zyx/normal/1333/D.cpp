#include <bits/stdc++.h>
using namespace std;
char a[5000];
vector<vector<int> > ans;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%c", &a[0]);
    for (int i = 1; i <= n; i++) scanf("%c", &a[i]);
    vector<int> v1, v2;
    for (int i = 1; i < n; i++)
        if (a[i] == 'R' && a[i + 1] == 'L') v1.push_back(i);
    int tot = 0;
    while (!v1.empty()) {
        ans.push_back(v1);
        tot += v1.size();
        for (auto i : v1) {
            a[i] = 'L', a[i + 1] = 'R';
        }
        for (auto i : v1) {
            if (i != 1 && a[i - 1] == 'R') v2.push_back(i - 1);
            if (i < n - 1 && a[i + 2] == 'L') v2.push_back(i + 1);
        }
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
        v1 = v2;
        v2.clear();
    }
    if (k > tot || k < ans.size())
        printf("-1");
    else {
        bool f = 1;
        int i, j;
        for (i = 0; i < ans.size(); i++) {
            for (j = 0; j < ans[i].size(); j++) {
                if (ans.size() - i == k) {
                    f = 0;
                    break;
                }
                printf("1 %d\n", ans[i][j]);
                k--;
            }
            if (f == 0) break;
        }
        printf("%d ", ans[i].size() - j);
        for (; j < ans[i].size(); j++) printf("%d ", ans[i][j]);
        printf("\n");
        for (i++; i < ans.size(); i++) {
            printf("%d ", ans[i].size());
            for (auto x : ans[i]) printf("%d ", x);
            printf("\n");
        }
    }
}