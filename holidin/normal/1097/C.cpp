#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;

int m[N], bg[N], en[N];

int main() {
    int i, j, k, n, top, balance;
    string s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> s;
        top = 0;
        balance = 0;
        for (j = 0; j < s.size(); ++j)
        if (s[j] == ')') {
            --balance;
            if (top > 0 && m[top] == '(')
                --top;
            else {
                ++top;
                m[top] = s[j];
            }
        } else {
            ++balance;
            ++top;
            m[top] = s[j];
        }
        int otkr = (top + balance) / 2, zkr =(top - balance) / 2;
        if (otkr == 0)
            ++bg[zkr];
        if (zkr == 0)
            ++en[otkr];
    }
    int ans = bg[0] / 2;
    for (i = 1; i < N; ++i)
        ans += min(bg[i], en[i]);
    cout << ans;
}