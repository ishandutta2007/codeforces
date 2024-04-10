#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int cnt[4];
int n, a[3], t[N], tn, vis[N];
int ans;
int s[4], v[4];

bool gao() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        s[i] = min(s[i], upper_bound(t, t + tn, v[i]) - t - sum);
        sum += s[i];
    }
    return s[0] + s[1] + s[2] + s[3] == tn;
}

bool judge(int mid) {
    for (int i = 0; i <= mid; i++) {
        s[0] = cnt[0]; s[1] = cnt[1];
        s[2] = s[3] = 0;
        if (a[0] + a[1] > a[2]) {
            s[3] += i;
            s[2] += i;
            s[0] += mid - i;
            s[1] += mid - i;
            s[2] += mid - i;
        } else {
            s[2] += i;
            s[3] += i;
            s[0] += mid - i;
            s[1] += mid - i;
            s[3] += mid - i;
        }
        if (gao()) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
    sort(a, a + 3);
    v[0] = a[0]; v[1] = a[1];
    if (a[0] + a[1] > a[2]) {
        v[2] = a[2];
        v[3] = a[0] + a[1];
    } else {
        v[2] = a[0] + a[1];
        v[3] = a[2];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        if (t[i] > a[0] + a[1] + a[2]) {
            printf("-1\n");
            return 0;
        } else if (t[i] > a[1] + a[2]) {
            ans++;
            vis[i] = 1;
        } else if (t[i] > a[0] + a[2]) {
            cnt[0]++;
            ans++;
            vis[i] = 1;
        } else if (t[i] > max(a[2], a[0] + a[1])) {
            cnt[1]++;
            ans++;
            vis[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) if (!vis[i]) t[tn++] = t[i];
    sort(t, t + tn);
    int l = 0, r = tn;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans + l);
    return 0;
}