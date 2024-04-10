#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
int dp[N];
int h[N];

struct A {
    int hei, step;
};
stack<A> s1, s2;

int main() {
//    ifstream cin("data.txt");
//    ofstream cout("test1.txt");

    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[1] = 0;
    s1.push({h[1], 0});
    s2.push({h[1], 0});
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        bool same = 0;
        while (!s1.empty() && s1.top().hei <= h[i]) {
            if (s1.top().hei == h[i]) same = 1;
            dp[i] = min(dp[i], s1.top().step + 1);
            s1.pop();
        }
        if (!same && !s1.empty()) dp[i] = min(dp[i], s1.top().step + 1);
        same = 0;
        while (!s2.empty() && s2.top().hei >= h[i]) {
            if (s2.top().hei == h[i]) same = 1;
            dp[i] = min(dp[i], s2.top().step + 1);
            s2.pop();
        }
        if (!same && !s2.empty()) dp[i] = min(dp[i], s2.top().step + 1);
        s1.push({h[i], dp[i]});
        s2.push({h[i], dp[i]});
    }
    cout << dp[n] << endl;
}