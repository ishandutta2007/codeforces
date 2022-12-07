#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int T, n;
int bit[N], input[N];
pair<int, int> a[N];

int lowbit(int x) {
    return x&(-x);
}

void add(int x, int w) {
    while (x < N) {
        bit[x] += w;
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            bit[i] = 0;
            a[i] = make_pair(x, i);
        }
        sort(a + 1, a + n + 1);
        int j = 0;
        for (int i = 1; i <= n; i = j) {
            for (j = i; j <= n && a[j].first == a[i].first; j++) {
                input[a[j].second] = i;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = input[i];
            int small_cnt = get(x - 1);
            int small_equal_cnt = get(x);
            ans += min(small_cnt, i - 1 - small_equal_cnt);
            add(x, 1);
        }
        cout << ans << endl;
    }
    return 0;
}