#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int n, a[MN], b[MN];

int calc(vector<int> p, vector<int> q) {
    vector<int> v1 = p, v2 = q;
    int sum = v1.back(); v1.pop_back();
    while (v1.size() < v2.size()) v1.push_back(0);
    while (v2.size() < v1.size()) v2.push_back(0);
    int zr = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (!zr) sum += 2 * v2[i];
        else sum += v2[i];
        if (v2[i] == 0) zr = 1;
        if (!zr) sum += 2 * v1[i];
        else sum += v1[i];
        if (v1[i] == 0) zr = 1;
    }
    return sum;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v1, v2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (a[i]) v1.push_back(b[i]);
            else v2.push_back(b[i]);
        }
        sort(v1.begin(), v1.end(), greater<>());
        sort(v2.begin(), v2.end(), greater<>());
        if (v1.empty() || v2.empty()) {
            int sum = 0;
            for (int p : v1) sum += p;
            for (int p : v2) sum += p;
            printf("%lld\n", sum);
            continue;
        }
        int sum1 = calc(v1, v2), sum2 = calc(v2, v1);
        printf("%lld\n", max(sum1, sum2));
    }

    return 0;
}