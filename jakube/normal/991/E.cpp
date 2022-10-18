#include <bits/stdc++.h>
using namespace std;

long long res = 0;

std::vector<long long> factorial;

void precompute_factorial(int ma)
{
    factorial.push_back(1);
    for (int i = 1; i <= ma; i++)
        factorial.push_back(factorial.back() * i);
}

void f(vector<int> v, int idx) {
    if (idx < 10) {
        int x = v[idx];
        if (x == 0) {
            f(v, idx + 1);
        } else {
            for (int y = 1; y <= x; y++) {
                v[idx] = y;
                f(v, idx + 1);
            }
        }
    } else {
        // starting index
        for (int i = 1; i < 10; i++) {
            if (v[i] == 0) continue;
            v[i]--;

            int sum = accumulate(v.begin(), v.end(), 0);
            long long x = factorial[sum];
            for (int c : v)
                x /= factorial[c];
            res += x;

            v[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> cnt(10, 0);
    for (char c : s)
        cnt[c - '0']++;
    
    precompute_factorial(20);
    f(cnt, 0);
    cout << res << '\n';
}