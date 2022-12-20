#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 45;
const int mod = 1e9 + 7;

vector<vector<long long> >  multm(vector<vector<long long> > a, vector<vector<long long> > b) {
    vector <vector<long long> > ans;
    int n = a.size();
    ans.resize(n);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        long long ct = 0;
        for (int l = 0; l < n; ++l)
            ct = (ct + a[i][l] * b[l][j]) % mod;
        ans[i].push_back(ct);
    }
    return ans;
}

vector<vector<long long> > bpm(vector<vector<long long> > x, int st) {
    if (st == 1)
        return x;
    else if (st % 2 == 0)
            return bpm(multm(x, x), st / 2);
        else
            return multm(bpm(multm(x, x), st / 2), x);
}

long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int s[1000];

int main() {
    int i, j, k, n, cnt = 0, cnt1 = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] == 0)
            ++cnt;
    }
    for (i = 0; i < cnt; ++i)
    if (s[i] == 0)
        ++cnt1;
    vector <vector<long long> > pt(cnt + 1), ans(cnt + 1);
    for (i = 0; i <= cnt; ++i) {
        pt[i].resize(cnt + 1);
        for (j = i; j <= i; ++j) {
            long long x = j, y = cnt - j, z = cnt - j, w = n - x - y - z;
            pt[i][j] = 1;
            if (j < cnt) {
                pt[i][j + 1] = (y * z * bp((n * (n - 1)) / 2, mod - 2)) % mod;
                pt[i][j] = (1 - pt[i][j + 1] + mod) % mod;
            }
            if (j > 0) {
                pt[i][j - 1] = (x * w * bp((n * (n - 1)) / 2, mod - 2)) % mod;
                pt[i][j] = (pt[i][j] - pt[i][j - 1] + mod) % mod;
            }
        }
        ans[i].resize(cnt + 1);
    }
    ans[cnt1][cnt1] = 1;
    ans = multm(ans, bpm(pt, k));
    cout << ans[cnt1][cnt];
}