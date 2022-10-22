#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 5e5 + 5;

int n, D;
int s[mxn], a[mxn];

int main() {
    scanf("%d %d", &n, &D);
    rep(i, n) scanf("%d %d", &s[i], &a[i]);
    std::vector <int> id0, id1;
    rep(i, n) if (s[i] <= a[i]) id0.push_back(i);
    else id1.push_back(i);
    std::sort(id0.begin(), id0.end(), [&] (int x, int y) { return a[x] != a[y] ? a[x] < a[y] : s[x] < s[y]; });
    std::sort(id1.begin(), id1.end(), [&] (int x, int y) { return s[x] != s[y] ? s[x] < s[y] : a[x] < a[y]; });
    std::vector <int> id(id0.size() + id1.size());
    std::merge(id0.begin(), id0.end(), id1.begin(), id1.end(), id.begin(), [&] (int x, int y) {
        if (s[x] == a[y]) return false;
        else return s[x] < a[y];
    });
    int ans = 0;
    for (int i : id) if (D <= s[i]) D = std::max(D, a[i]), ++ ans;
    printf("%d\n", ans);
    return 0;
}