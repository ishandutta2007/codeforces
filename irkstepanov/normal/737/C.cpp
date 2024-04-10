#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, r;
    scanf("%d%d", &n, &r);
    --r;

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    vector<int> cnt(n + 1);
    int dd = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (i == r) {
            if (x) {
                dd = 1;
            }
            ++cnt[0];
        } else {
            if (i != r && !x) {
                ++cnt[n];
            } else {
                ++cnt[x];
            }
        }
    }

    int sum_right = 0;
    for (int i = 2; i <= n; ++i) {
        sum_right += cnt[i];
    }
    int empty_left = 0;
    for (int i = 0; i <= 1; ++i) {
        if (!cnt[i]) {
            ++empty_left;
        }
    }

    int ans = n + dd;

    for (int depth = 1; depth < n; ++depth) {
        ans = min(ans, max(sum_right, empty_left) + dd);
        sum_right -= cnt[depth + 1];
        if (!cnt[depth + 1]) {
            ++empty_left;
        }
    }

    printf("%d\n", ans);

}