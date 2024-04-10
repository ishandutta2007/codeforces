#include <bits/stdc++.h>

using namespace std;

using vec = vector<int>;

const int N = 1e6 + 10;

char S[N];

int n, a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> (S + 1);
    int l = 1, r = n;
    vec ans;
    for (int i = n; i > 1; --i)
        if (S[i] != S[i - 1]) {
            if (S[i] == 'L') {
                ans.emplace_back(-r);
            } else {
                ans.emplace_back(r);
            }
            r--;
        } else {
            if (i & 1) {
                if (S[i] == 'L') {
                    ans.emplace_back(-l);
                } else {
                    ans.emplace_back(l);
                }
            } else {
                if (S[i] == 'L') {
                    ans.emplace_back(l);
                } else {
                    ans.emplace_back(-l);
                }
            }
            ++l;
        }
    if (S[1] == 'L') {
        ans.emplace_back(-l);
    } else {
        ans.emplace_back(l);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i) {
        if (ans[i] < 0) {
            cout << a[-ans[i]] << " L\n";
        } else {
            cout << a[ans[i]] << " R\n";
        }
    }
    return 0;
}