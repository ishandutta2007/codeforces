#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 20;

map <vector <int>, long long> dp[N];
int t, e[N];

long long cnt(vector <int> v, long long ost) {
    sort(v.begin(), v.end());
    if (v.size() != 16)
        exit(1);
    if (ost == 0) {
        for (int i = 0; i < v.size(); ++i)
        if (v[i] > t || v[15] == 0)
            return 0;
        return 1;
    }
    if (dp[ost].count(v) == 0) {
        vector <int> a;
        dp[ost][v] = 0;
        if (v[15] == 0)
            dp[ost][v] = cnt(v, ost - 1);
        for (int i = (v[15] == 0); i < v.size(); ++i)
        if (v[i] < t) {
            a = v;
            ++a[i];
            dp[ost][v] += cnt(a, ost - 1);
        }
    }
    return dp[ost][v];
}

int main() {
    int i, j, k, l, r;
    long long n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    vector <int> v(16);
    for (j = 0; j < 16; ++j)
        v[j] = 0;
    bool flag = 0;
    for (i = 15; i >= 0; --i) {
        if (!flag && i > 0 && cnt(v, i) >= n)
            continue;
        if (!flag && i > 0) {
            n -= cnt(v, i);
        }
        for (j = !flag; j < 16; ++j) {
            vector <int> a = v;
            ++a[j];
            if (cnt(a, i) < n)
                n -= cnt(a, i);
            else {
                flag = 1;
                ++v[j];
                e[i] = j;
                break;
            }
        }
    }
    i = 15;
    while (e[i] == 0 && i > 0)
        --i;
    while (i >= 0) {
        if (e[i] < 10)
            cout << (char) (e[i] + '0');
        else
            cout << (char) (e[i] - 10 + 'a');
        --i;
    }
}