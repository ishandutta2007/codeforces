#include <bits/stdc++.h>
using namespace std;

int MOD = 1'000'000'007;


class Hashing
{
public:
    Hashing(std::string const& s, int p = 31, int mod = 1'000'000'007) 
      : mod(mod)
    {
        psum.push_back(0);
        long long power = 1;
        long long inv = inverse(p, mod);
        inv_powers.push_back(1);
        for (char c : s) {
            psum.push_back((psum.back() + power * (c - 'a' + 1)) % mod);
            power = power * p % mod;;
            inv_powers.push_back(inv_powers.back() * inv % mod);
        }
    }

    int hash(int i, int j) {
        long long h = psum[j+1] - psum[i];
        if (h < 0)
            h += mod;
        return h * inv_powers[i] % mod;
    }

private:
    long long inverse(long long base, int M) {
        int e = M - 2;
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

    std::vector<int> psum;
    std::vector<int> inv_powers;
    int mod;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    Hashing hashing(s);

    vector<int> res((n + 1) / 2);
    int last = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        int start = (n - 1) / 2 - i;
        int end = start + i * 2 + (n % 2 == 0);
        int x = min(end - start, last + 2);
        if (x % 2 == 0)
            x--;
        while (x > 0 && hashing.hash(start, start + x - 1) != hashing.hash(end - x + 1, end))
            x -= 2;
        last = x;
        res[i] = x;
    }
    reverse(res.begin(), res.end());
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}