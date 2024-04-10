#include <bits/stdc++.h>
using namespace std;


int MOD = 1e9 + 7;

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

void computePrimesLargest(int n, std::vector<int> &largest)
{
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> largest;
    computePrimesLargest(k, largest);
    vector<int> moebius(k + 1);
    for (int i = 1; i <= k; i++) {
        int last = -1;
        int num = i;
        int cnt = 0;
        bool zero = false;
        while (num > 1) {
            if (largest[num] == last) {
                zero = true;
                break;
            }
            last = largest[num];
            num /= largest[num];
            cnt++;
        }
        if (zero)
            moebius[i] = 0;
        else 
            moebius[i] = cnt & 1 ? -1 : 1;
    }

    vector<long long> powers(k + 1);
    for (int i = 0; i <= k; i++) {
        powers[i] = power(i, n);
    }
    
    vector<int> f(n, 0);
    long long result = 0;
    long long count = 1;

    vector<long long> old(k + 1, 0);
    old[1] = 1;
    for (int i = 2; i <= k; i++) {
        vector<int> divisors(1, 1);
        int num = i;
        while (num > 1) {
            int s = divisors.size();
            int x = largest[num];
            for (int z = 0; z < s; z++) {
                divisors.push_back(divisors[z] * x);
            }
            num /= x;
        }
        for (int div : divisors) {
            count -= old[div];
            old[div] = moebius[div] * powers[i / div];
            count += old[div];
        }
        count = ((count % MOD) + MOD) % MOD;
        result += count ^ i;
    }
    cout << result % MOD << '\n';
}