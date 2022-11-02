#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, kp[N], t[N];

long long ans;

vector<int> fr = {0}, pr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), std::cout.tie(0);
    for (int i = 2; i <= N; ++i) {
        if (kp[i]) continue;
        for (int j = i; j <= N; j += i) {
            if (!kp[j]) kp[j] = i;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) {
        char N;
        cin >> N;
        vector<int> sz;
        int s = t[i];
        while (s > 1) sz.push_back(kp[s]), s /= kp[s];
        if (N == '*') {
            for (auto x : sz) pr[x].push_back(i);
        }
        if (N == '/') {
            int mini = i;
            for (auto x : sz) {
                if (pr[x].size() > 0) {
                    mini = min(mini, pr[x].back());
                    pr[x].pop_back();
                } else {
                    mini = 0;
                }
            }
            while (fr.size() > 0 && fr.back() >= mini) fr.pop_back();
        }
        ans += fr.size();
        fr.push_back(i);
    }
    cout << ans << "\n";
    return 0;
}