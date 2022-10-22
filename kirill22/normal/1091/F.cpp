#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int w = -1, g = -1;
    vector<long long> need(n);
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            need[i] = a[i];
            if (w == -1) {
                w = i;
            }
            sum += a[i];
            ans += a[i] * 3;
        }
        if (s[i] == 'G') {
            need[i] = a[i];
            if (g == -1) {
                g = i;
            }
            sum += a[i];
            ans += a[i] * 5;
        }
        if (s[i] == 'L') {
            sum -= a[i];
            if (sum < 0) {
                if (w != -1) {
                    need[w] += abs(sum);
                    ans += abs(sum) * 3;
                } else {
                    need[g] += abs(sum);
                    ans += abs(sum) * 5;
                }
                sum = 0;
            }
            ans += a[i];
        }
    }
    vector<int> tmpw, tmpg;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            tmpw.push_back(i);
        }
        if (s[i] == 'G') {
            tmpg.push_back(i);
        }
        if (s[i] == 'L') {
            while (a[i]) {
                if ((int) tmpw.size()) {
                    int j = tmpw.back();
                    long long x = min(a[i], need[j]);
                    a[i] -= x;
                    need[j] -= x;
                    if (!need[j]) {
                        tmpw.pop_back();
                    }
                } else {
                    int j = tmpg.back();
                    long long x = min(a[i], need[j]);
                    a[i] -= x;
                    need[j] -= x;
                    if (!need[j]) {
                        tmpg.pop_back();
                    }
                }
            }
        }
    }
    //cout << ans << endl;
    //for (auto x : need) cout << x << " "; cout << endl;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            while (j <= i && need[i]) {
                if (!need[j]) {
                    j++;
                    continue;
                }
                if (j == i) {
                    ans -= need[i] * 2;
                    need[i] = 0;
                    break;
                }
                long long x = min(need[i], need[j]);
                need[i] -= x;
                need[j] -= x;
                ans -= x * 4;
            }
        }
    }
    j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            while (j <= i && need[i]) {
                if (!need[j]) {
                    j++;
                    continue;
                }
                if (j == i) {
                    ans -= need[i] * 1;
                    need[i] = 0;
                    break;
                }
                long long x = min(need[i], need[j]);
                need[i] -= x;
                need[j] -= x;
                ans -= x * 2;
            }
        }
    }
    cout << ans;
}