#include <bits/stdc++.h>
using namespace std;

class Bitset {
public:
    Bitset(int n=0) : data((n + 63)/64) {}
    Bitset(Bitset const& o) : data(o.data) {}

    Bitset& operator^=(Bitset const& o) {
        for (auto i = 0u; i < data.size(); i++)
            data[i] ^= o.data[i];
        return *this;
    }

    Bitset& operator|=(Bitset const& o) {
        for (auto i = 0u; i < data.size(); i++)
            data[i] |= o.data[i];
        return *this;
    }

    Bitset& operator<<=(unsigned cnt) {
        unsigned long long last = 0;
        for (auto i = 0u; i < data.size(); i++) {
            auto cur = data[i];
            data[i] = (cur << cnt) | (last >> (64 - cnt));
            last = cur;
        }
        return *this;
    }

    Bitset operator<<(unsigned cnt) const {
        auto cpy = *this;
        cpy <<= cnt;
        return cpy;
    }

    bool check(int idx) const {
        return data[idx/64] & (1LL << (idx%64));
    }

    void set(int idx) {
        data[idx/64] |= (1LL << (idx%64));
    }

    int first_set() const {
        for (auto i = 0u; i < data.size(); i++) {
            if (data[i] == 0)
                continue;
            int idx = 64 * i; 
            auto bits = data[i];
            while (!(bits & 1)) {
                idx++;
                bits >>= 1;
            }
            return idx;
        }
        return -1;
    }

private:
    std::vector<unsigned long long> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> cnt(9);
    for (auto& x : cnt)
        cin >> x;
    long long W = cnt[0];

    long long offset = 0;
    const int N = 840;
    long long multiples = 0;
    for (int i = 1; i <= 8; i++) {
        int mod = N / i;
        int take = cnt[i] % mod;
        if (cnt[i] > take)
            take += N / i;
        multiples += (cnt[i] - take) / mod;
        cnt[i] = take;
    }

    long long sum = 0;
    for (int i = 1; i <= 8; i++) {
        sum += cnt[i] * i;
    }
    Bitset bs(sum + 1);
    bs.set(0);
    for (int i = 1; i <= 8; i++) {
        for (int c = 0; c < cnt[i]; c++) {
            bs |= bs << i;
        }
    }

    long long best = 0;
    for (int w = 0; w <= min(sum, W); w++) {
        if(bs.check(w)) {
            long long rem = W - w;
            long long needed = rem / N;
            best = max(best, min(needed, multiples) * N + w);
        }
    }
    cout << best << '\n';
}