#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
int a[200000];
vector<int> as[200000];
int mx[5100000][8];
int st[200000][15];

void trans(int x) {
    int v = a[x];
    for (int i = 2; i * i <= v; ++i) {
        while (v % (i * i) == 0) v /= i * i;
        if (v % i == 0) as[x].push_back(i), v /= i;
    }
    if (v > 1) as[x].push_back(v);
}

void updateMx(int t, int i, int x, int c) {
    if (i == as[t].size()) {
        mx[x][c] = max(mx[x][c], t);
        return;
    }
    updateMx(t, i + 1, x, c);
    updateMx(t, i + 1, x * as[t][i], c - 1);
}

void calcSt(int t, int i, int x, int c) {
    if (i == as[t].size()) {
        for (i = 0; i <= 7; ++i) st[t][i + c] = max(st[t][i + c], mx[x][i]);
        return;
    }
    calcSt(t, i + 1, x, c);
    calcSt(t, i + 1, x * as[t][i], c - 1);
}

struct _qs {
    int l, r, i;
    void scan(int idx) {
        i = idx;
        cin >> l >> r;
    }
    bool operator<(const _qs &p) const {
        return r < p.r;
    }
} qs[1100000];
int ans[1100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        trans(i);
        calcSt(i, 0, 1, as[i].size());
        for (int j = 1; j < 15; ++j) st[i][j] = max(st[i][j], st[i][j - 1]);
        updateMx(i, 0, 1, as[i].size());
	}
	
	for (int i = 0; i < q; ++i) qs[i].scan(i);
	sort(qs, qs + q);
	for (int i = 0, j = 1; i < q; ++i) {
        while (j <= qs[i].r) {
            for (int k = 0; k < 15; ++k)
                st[j][k] = max(st[j][k], st[j - 1][k]);
            ++j;
        }
        int s = 0, e = 15;
        while (s < e) {
            int m = (s + e) / 2;
            if (qs[i].l <= st[qs[i].r][m]) e = m;
            else s = m + 1;
        }
        ans[qs[i].i] = s;
	}
	for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
}