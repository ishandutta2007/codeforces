#include <bits/stdc++.h>
using namespace std;

vector<long long> factorial;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int MOD = 998'244'353;

    factorial.push_back(1);
    for (int i = 1; i <= 5000; i++)
        factorial.push_back((factorial.back() * i) % MOD);

    vector<vector<long long>> ncr(5001, vector<long long>(5001, 0));
    for (int n = 0; n <= 5000; n++) {
        ncr[n][0] = 1;
        ncr[n][n] = 1;
        for (int k = 1; k < n; k++) {
            ncr[n][k] = (ncr[n-1][k-1] + ncr[n-1][k]) % MOD;
        }
    }

    vector<int> sizes = {a, b, c};
    vector<long long> results(3, 0);

    for (int i = 0; i < 3; i++) {
        int x = sizes[i];
        int y = sizes[(i + 1) % 3];
        for (int left = 0; left <= min(x, y); left++) {
            long long res = 1;
            res *= ncr[x][left];
            res %= MOD;
            res *= ncr[y][left];
            res %= MOD;
            res *= factorial[left];
            res %= MOD;
            results[i] += res;
        }
        results[i] %= MOD;
    }

    long long cnt = results[1];
    cnt *= results[2];
    cnt %= MOD;
    cnt *= results[0];
    cnt %= MOD;

    cout << cnt << endl;
}