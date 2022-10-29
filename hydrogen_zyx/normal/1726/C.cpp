
#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

char c[N];
int r[N];

int solve(int ql, int qr) {
    if (ql > qr) return 0;
    int ans = 0;
    int now = ql;
    while (now <= qr) {
        int nxt = r[now];
        ans += solve(now + 1, nxt - 1);
        now = nxt + 1;
    }
    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i++) cin >> c[i];
        stack<int> stk;
        for (int i = 1; i <= n; i++) {
            if (c[i] == '(') stk.push(i);
            else {
                r[stk.top()] = i;
                stk.pop();
            }
        }
        cout << solve(1, n) << endl;
    }
}