#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define inf (int)1e9

int n, a, b;
vi c;
int dp[100][100][100];
int path[100][100][100];

int solve(int pos, int last, int current) {
    if (pos == n - 1) {
        if (last < 0 && current < 0) return 0;
        return inf;
    }
    if (dp[pos + 80][last + 80][current + 80] != -1)
        return dp[pos + 80][last + 80][current + 80];
    int ans = inf, val = 0, next = c[pos + 1];
    int curr = current, temp = last;
    bool flag = true;
    while (next >= 0 || curr >= 0 || temp >= 0 || flag) {
        if (next < 0 && curr < 0 && temp < 0) flag = false;
        if (temp < 0) {
            int tem = ans;
            ans = min(ans, val + solve(pos + 1, curr, next));
            if (ans != tem) path[pos][last][current] = val;
        }
        next -= b;
        temp -= b;
        curr -= a;
        val++;
    }
    return dp[pos + 80][last + 80][current + 80] = ans;
}

void print_path(int pos, int last, int current) {
    if (pos == n - 1) {
        return;
    }
    for (int i = 0; i < path[pos][last][current]; i++) cout << (pos + 1) << " ";
    int v1 = current - a * path[pos][last][current];
    int v2 = c[pos + 1] - b * path[pos][last][current];
    print_path(pos + 1, v1, v2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    c.resize(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    memset(dp, -1, sizeof dp);
    int ans = solve(1, c[0], c[1]);
    cout << ans << "\n";
    print_path(1, c[0], c[1]);
    cout << endl;
    return 0;
}