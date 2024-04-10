#include <bits/stdc++.h>
using namespace std;

std::vector<int> compute_primes(int n)
{
    std::vector<bool> m(n + 1, false);

    int root = std::sqrt(n) + 1;
    for (int i = 1; i <= root; i++) {
        for (int j = 1; j <= root; j++) {
            int a = 4 * i * i + j * j;
            int b = 3 * i * i + j * j;
            int c = 3 * i * i - j * j;

            if (a <= n && (a % 12 == 1 || a % 12 == 5))
                m[a].flip();
            if (b <= n && b % 12 == 7)
                m[b].flip();
            if (i > j && c <= n && c % 12 == 11)
                m[c].flip();
        }
    }

    for (int i = 5; i * i <= n; i++) {
        if (m[i]) {
            for (int j = 1; j * i * i <= n; j++)
                m[j * i * i] = false;
        }
    }

    std::vector<int> primes = {2, 3};
    for (int i = 5; i < n; i++) {
        if (m[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    auto primes = compute_primes(10'000);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0)
            continue;
        for (int p : primes) {
            while (v[i] % (p*p) == 0)
                v[i] /= p*p;
        }
    }

    set<int> s(v.begin(), v.end());
    vector<int> ordered(s.begin(), s.end());
    int zero = -1;
    if (s.count(0))
        zero = lower_bound(ordered.begin(), ordered.end(), 0) - ordered.begin();
    for (int& x : v)
        x = lower_bound(ordered.begin(), ordered.end(), x) - ordered.begin();

    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        vector<bool> here(ordered.size(), false);
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (!here[v[j]]) {
                here[v[j]] = true;
                cnt++;
            }
            
            if (cnt > 1 && zero >= 0 && here[zero])
                res[cnt - 2]++;
            else
                res[cnt - 1]++;
        }
    }

    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
    
}