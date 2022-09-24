#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dbl;

const int INF = (int)1.01e9;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<int> b(n);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        vector<ll> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i - 1];


        vector<ll> t1(n + 1);
        vector<ll> t2(n + 1);
        for (int i = 0; i < n; i++) {
            int L = i - 1;
            int R = n;
            while (R - L > 1) {
                int M = (L + R) >> 1;
                if (s[M + 1] - s[i] > a[i]) R = M;
                else L = M;
            }
            ll x = a[i];
            x -= s[R] - s[i];


            t2[R] += x;
            t1[i]++;
            t1[R]--;
        }

        vector<ll> ans;
        for (int i = 0; i < n; i++) {
            if (i) t1[i] += t1[i - 1];
            t2[i] += 1LL * t1[i] * b[i];
            ans.push_back(t2[i]);
        }
        for (int i = 0; i < n; i++) printf("%lld%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    }

    return 0;
}