#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int N = 150005;
const int INF = 0x3f3f3f3f;

int n, t[N], sb[N], sn;
int mis[N];
int tmp[N], tn;

set<pair<int, int> > s;

int main() {
    scanf("%d", &n);
    t[0] = INF;
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    if (n&1) t[n + 1] = INF;
    else t[n + 1] = -INF;
    for (int i = 1; i <= n; i++) {
        if (i&1) {
            if (t[i] >= t[i - 1] || t[i] >= t[i + 1]) {
                sb[sn++] = i;
                mis[i] = 1;
            }
        } else {
            if (t[i] <= t[i - 1] || t[i] <= t[i + 1]) {
                sb[sn++] = i;
                mis[i] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < sn && i < 1; i++) {
        for (int v = sb[i] - 1; v <= sb[i] + 1; v++) {
            if (v == 0 || v == n + 1) continue;
            for (int j = 1; j <= n; j++) {
                if (j == v) continue;
                if (s.find(make_pair(v, j)) != s.end()) continue;
                s.insert(make_pair(v, j));
                s.insert(make_pair(j, v));
                swap(t[v], t[j]);
                tn = 0;
                int tot = sn;
                for (int x = -1; x <= 1; x++) {
                    int vv = v + x;
                    if (vv == 0 || vv == n + 1) continue;
                    tmp[tn++] = vv;
                }
                for (int x = -1; x <= 1; x++) {
                    int vv = j + x;
                    if (vv == 0 || vv == n + 1) continue;
                    tmp[tn++] = vv;
                }
                sort(tmp, tmp + tn);
                tn = unique(tmp, tmp + tn) - tmp;
                for (int i = 0; i < tn; i++) {
                    int v = tmp[i];
                    if (!mis[v]) {
                        if (v&1) {
                            if (t[v] >= t[v - 1] || t[v] >= t[v + 1])
                                tot++;
                        } else {
                            if (t[v] <= t[v - 1] || t[v] <= t[v + 1])
                                tot++;
                        }
                    } else {
                        if (v&1) {
                            if (t[v] < t[v - 1] && t[v] < t[v + 1])
                                tot--;
                        } else {
                            if (t[v] > t[v - 1] && t[v] > t[v + 1])
                                tot--;
                        }
                    }
                }
                //printf("%d %d %d\n", v, j, tot);
                if (tot == 0) ans++;
                swap(t[v], t[j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}