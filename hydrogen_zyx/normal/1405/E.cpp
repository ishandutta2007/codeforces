#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
int a[N];
int bit[N];

void add(int k, int x) {
    while (k < N) {
        bit[k] += x;
        k += k & -k;
    }
}

int query(int k) {
    int ans = 0;
    while (k) {
        ans += bit[k];
        k -= k & -k;
    }
    return ans;
}

struct node {
    int s, e, num, ans;
} que[N];

bool cmp1(node a, node b) { return a.e < b.e; }
bool cmp2(node a, node b) { return a.num < b.num; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> que[i].s >> que[i].e;
        que[i].s++;
        que[i].e = n - que[i].e;
        que[i].num = i;
    }
    sort(que + 1, que + 1 + q, cmp1);
    int now = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 0) {
            int l = 0, r = i + 1, mid;
            while (l + 1 < r) {
                mid = (l + r) >> 1;
                if (query(mid) >= a[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            add(1, 1);
            add(r, -1);
        }
        while (now <= q && que[now].e <= i) {
            que[now].ans = query(que[now].s);
            now++;
        }
    }
    sort(que + 1, que + 1 + q, cmp2);
    for (int i = 1; i <= q; i++) cout << que[i].ans << endl;
}