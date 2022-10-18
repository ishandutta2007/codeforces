#include <bits/stdc++.h>
using namespace std;
    
void compute_moebius(int n, std::vector<int> &moebius)
{
    moebius.assign(n + 1, 2);
    vector<int> divisors(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (divisors[i] == 0) {
            for (int j = 1, jm = 1; j * i <= n; j++, jm++) {
                if (jm == i) {
                    jm = 0;
                    moebius[j*i] = 0;
                }
                divisors[j*i]++;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (moebius[i] == 2)
            moebius[i] = (divisors[i] & 1) ? -1 : 1;
    }
}

long long fastexp(long long base, int e)
{
    long long result = 1;
    while (e) {
        if (e & 1)
            result *= base;
        base *= base;
        e >>= 1;
    }
    return result;
}

long long root(long long x, int e) {
    long long test = pow(x, 1. / e) + 0.1;
    if (fastexp(test, e) <= x)
        return test;
    else
        return test - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    vector<long long> ns(T);
    for (auto& x : ns)
        cin >> x;

    vector<int> moebius;
    compute_moebius(60, moebius);

    for (auto n : ns) {
        auto cnt = n - 1;
        for (int e = 2; e <= 60; e++) {
            cnt += (root(n, e) - 1) * moebius[e];
        }
        cout << cnt << '\n';
    }
}