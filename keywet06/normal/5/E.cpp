#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 2000005;

int n;
int h[N], ind[N];

set<int> used;

map<int, int> cnt;

bool cmp(int p, int q) { return h[p] > h[q]; }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
        ind[i] = i;
    }
    sort(ind, ind + n, cmp);
    int first_ = 0;
    int64 total = 0;
    while (first_ < n) {
        int p = first_;
        while (first_ < n && h[ind[first_]] == h[ind[p]]) first_++;
        int q = first_ - 1;
        if (used.empty()) {
            total += int64(q - p + 1) * int64(q - p) / 2;
            for (int i = p; i <= q; ++i) {
                used.insert(ind[i]);
            }
        } else {
            if (used.size() == 1) {
                total += int64(q - p + 1) * int64(q - p) / 2;
                total += q - p + 1;
                for (int i = p; i <= q; ++i) {
                    used.insert(ind[i]);
                }
            } else {
                cnt.clear();
                for (int i = p; i <= q; ++i) {
                    set<int>::iterator it = used.lower_bound(ind[i]);
                    if (it == used.end()) it = used.begin();
                    cnt[*it]++;
                }
                for (map<int, int>::iterator it = cnt.begin(); it != cnt.end();
                     ++it) {
                    int t = it->second;
                    total += int64(t) * int64(t - 1) / 2;
                    total += 2 * t;
                }
                for (int i = p; i <= q; ++i) {
                    used.insert(ind[i]);
                }
            }
        }
    }
    cout << total << "\n";
    return 0;
}