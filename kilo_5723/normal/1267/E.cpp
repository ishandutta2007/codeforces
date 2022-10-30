#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+5;

int a[N][N];

int ans;

// int b[N];
pair<int, int> b[N];
typedef pair<int, int> pii;

inline int cmp(const pii &a, const pii &b) { return a.first > b.first; }

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = m;
    vector<int> Ans;
    for (int i=1; i<=m; ++i) Ans.push_back(i);

    for (int i=1; i<=n-1; ++i) {
        int sum = 0;
        for (int j=1; j<=m; ++j) {
            b[j] = {a[j][n]-a[j][i], j};
            sum += b[j].first;
        }

        sort(b+1, b+m+1, cmp);
        vector<int> tans; tans.clear();
        if (sum <= 0) {
            ans = 0;
            Ans = tans;
            break;
        }
        
        for (int j=1; j<=m; ++j) {
            sum -= b[j].first;
            tans.push_back(b[j].second);
            if (sum <= 0) {
                if (j < ans) {
                    ans = j;
                    Ans = tans;
                }
                break;
            }
        }
    }

    printf("%d\n", ans);
    int sz = Ans.size();
    for (int i=0; i<sz; ++i)
        printf("%d%c", Ans[i], i==sz-1? '\n':' ');
    // printf("%d\n", Ans[sz-1]);

    return 0;
}