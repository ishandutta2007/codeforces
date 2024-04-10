#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
string s;
int k, n;
bool f;
void dfs(int p) {
    char c = s[p];
    if (p >= k) {
        if (s[p - k] == '?') {
            s[p - k] = c;
            dfs(p - k);
        } else if (s[p - k] != c) {
            f = 0;
            return;
        }
    }
    if (p + k < s.length()) {
        if (s[p + k] == '?') {
            s[p + k] = c;
            dfs(p + k);
        } else if (s[p + k] != c) {
            f = 0;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        if (k & 1) {
            cout << "NO" << endl;
            continue;
        }
        f = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '?') dfs(i);
        }
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '1') cnt1++;
            if (s[i] == '0') cnt0++;
            if (s[i] == '?') cnt2++;
        }
        if (abs(cnt1 - cnt0) > cnt2) f = 0;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}