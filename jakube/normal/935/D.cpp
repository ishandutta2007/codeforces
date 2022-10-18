#include <bits/stdc++.h>
using namespace std;

int MOD = 1'000'000'007;

long long power(long long base, int e, int M=MOD)
{
    long long result = 1;
    base %= M;
    while (e) {
        if (e & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        e >>= 1;
    }
    return result;
}

auto inverse(long long x) {
    return power(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    long long m_inv = inverse(m);
    long long inv2 = inverse(2);

    long long total_prob = 0;
    long long cur_prob = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] && b[i]) {
            if (a[i] < b[i])
                break; // not possible
            if (a[i] > b[i]) {
                total_prob += cur_prob;
                break; // always
            }
        } else {
            if (b[i]) {
                // a[i] == 0
                // greater
                total_prob += (m - b[i]) * m_inv % MOD * cur_prob % MOD;
                // equal
                cur_prob = cur_prob * m_inv % MOD;
            } else if (a[i]) {
                total_prob += (a[i] - 1) * m_inv % MOD * cur_prob % MOD;
                cur_prob = cur_prob * m_inv % MOD;
            } else {
                long long same = m_inv;
                long long smaller = (MOD + 1 - same) * inv2 % MOD;
                total_prob += smaller  * cur_prob % MOD;
                cur_prob = cur_prob * same % MOD;
            }
        }
    }
    cout << total_prob % MOD << endl;
}