#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1000005];
vector<int> v[1000005];
int nxt[1000005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cin >> a + 1;
    int p = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '1') continue;
        p = max(p, i);
        while (a[p + 1] == '0' || a[p + 1] == '?') p++;
        nxt[i] = max(nxt[i], p - i + 1);
    }
    p = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '0') continue;
        p = max(p, i);
        while (a[p + 1] == '1' || a[p + 1] == '?') p++;
        nxt[i] = max(nxt[i], p - i + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == '1' && a[i] != '1') {
            int p = i;
            while (a[p + 1] == '0' || a[p + 1] == '?') p++;
            for (int j = 1; j <= p - i + 1; j++) v[j].push_back(i);
        } else if (a[i - 1] == '0' && a[i] != '0') {
            int p = i;
            while (a[p + 1] == '1' || a[p + 1] == '?') p++;
            for (int j = 1; j <= p - i + 1; j++) v[j].push_back(i);
        }
    }
    for (int len = 1; len <= n; len++) {
        int cnt = 0;
        int pos = 1;
        int now = 0;
        while (pos <= n) {
            int npos = 0x3f3f3f3f;
            if (nxt[pos] >= len) npos = min(npos, pos + len);
            while (now < v[len].size() && v[len][now] < pos) now++;
            if (now < v[len].size()) npos = min(npos, v[len][now] + len);
            if (npos != 0x3f3f3f3f) cnt++;
            pos = npos;
        }
        cout << cnt << ' ';
    }
}