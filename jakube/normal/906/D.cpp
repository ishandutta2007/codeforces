#include <bits/stdc++.h>
using namespace std;

long long mod(long long num, int MOD) {
    return num < MOD ? num : MOD + num % MOD;
}

long long power(long long base, int e, int M)
{
    long long result = 1;
    base = mod(base, M);
    while (e) {
        if (e & 1)
            result = mod(result * base, M);
        base = mod(base * base, M);
        e >>= 1;
    }
    return result;
}

int m;
vector<int> v;
vector<int> phi;

long long exp(int l, int r, int i) {
    if (l == r) {
        return v[l];
    }

    if (phi[i] == 1) {
        return 1;
    }

    return power(v[l], mod(exp(l + 1, r, i + 1), phi[i + 1]), phi[i]);
}

int totient(int num)
{
    int res = num;
    for (int div = 2; div * div <= num; div++) {
        if (num % div == 0) {
            res /= div;
            res *= div - 1;
            while (num % div == 0) {
                num /= div;
            }
        }
    }
    if (num > 1) {
        res /= num;
        res *= num - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    phi.push_back(m);
    while (phi.back() > 1) {
        phi.push_back(totient(phi.back()));
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << exp(l, r, 0) % m << '\n';
    }
}