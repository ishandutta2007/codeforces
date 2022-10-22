#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int n;
    scanf("%d", &n);
    static char temp[100005];
    scanf("%s", temp);
    string s = temp;
    vector <int> sum(n + 1);
    sum[0] = 100005;
    rep(i, n) sum[i + 1] = (s[i] == '1' ? 1 : -1) + sum[i];
    static int lst[200010];
    memset(lst, -1, sizeof(lst));
    int ans = 0;
    rep(i, n + 1) {
        if (lst[sum[i]] != -1)
            ans = max(ans, i - lst[sum[i]]);
        else
            lst[sum[i]] = i;
    }
    printf("%d\n", ans);
    return 0;
}