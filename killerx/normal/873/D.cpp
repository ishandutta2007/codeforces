#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void random_shuffle(vector <int> &a, int l, int r, int &k) {
    if (!k) return ;
    if (l + 1 == r) return ;
    int m = (l + r) >> 1;
    vector <int> nw;
    for (int i = l; i < r; ++ i) nw.pb(a[i]);
    for (int i = l; i < m; ++ i) a[i] = nw[r - l - (m - i)];
    for (int i = m; i < r; ++ i) a[i] = nw[i - m];
    k -= 2;
    random_shuffle(a, l, m, k);
    random_shuffle(a, m, r, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> a(n);
    rep(i, n) a[i] = i;
    -- k;
    random_shuffle(a, 0, n, k);
    if (k != 0) puts("-1");
    else {
        rep(i, n) printf("%d ", a[i] + 1);
        printf("\n");
    }
    return 0;
}