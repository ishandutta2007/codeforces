#include <bits/stdc++.h>

using namespace std;

const int N = 200043;
const int K = 10;
const int Z = 1 << K;

int rem[Z];
int t[N];

int get(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result ^= t[r];
    return result;
}

void change(int i, int delta) {
    for (; i < N; i = (i | (i + 1))) t[i] ^= delta;
}

int get(int l, int r) { return get(r) - get(l - 1); }

int ans[N];
int c[N];
int cnt[N];
int n, m;
int ls[N];
int rs[N];
vector<int> qs[N];
vector<int> qs2[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        cnt[c[i]]++;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        ls[i] = l;
        rs[i] = r;
        qs[l].push_back(i);
        qs2[r + 1].push_back(i);
    }
    for (int i = m; i >= 1; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            rem[i % (1 << K)]++;
            int r = i;
            while (true) {
                int l = r - Z + 1;
                l = max(1, l);
                if (l > r) break;
                int diff = i - l;
                diff >>= K;
                change(l, diff);
                change(r + 1, diff);
                r -= Z;
            }
        }
        for (auto x : qs[i]) {
            int cur = (get(i)) << K;
            for (int k = 0; k < Z; k++) {
                int dist = (k - i) % Z;
                if (dist < 0) dist += Z;
                if (rem[k] & 1) cur ^= dist;
            }
            ans[x] ^= cur;
        }
        for (auto x : qs2[i]) {
            int cur = (get(ls[x])) << K;
            for (int k = 0; k < Z; k++) {
                int dist = (k - ls[x]) % Z;
                if (dist < 0) dist += Z;
                if (rem[k] & 1) cur ^= dist;
            }
            ans[x] ^= cur;
        }
    }
    for (int i = 0; i < q; i++)
        if (ans[i] == 0)
            printf("B");
        else
            printf("A");
}