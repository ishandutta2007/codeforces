#include <bits/stdc++.h>
using namespace std;

template <int BITS>
class BigInteger
{
public:
    BigInteger(long long value) {
        bool negative = value < 0;
        value = std::abs(value);
        for (int i = 0; i < BLOCK_CNT; i++) {
            blocks[i] = value & MASK_USED_BITS;
            value >>= BITS_PER_BLOCK;
        }
        if (negative) two_complement(*this);
    }

    int sign() const {
        if (blocks.back() >> (BITS_PER_BLOCK - 1)) return -1;
        for (auto const& block : blocks) {
            if (block > 0u) return 1;
        }
        return 0;
    }
    static int cmp(BigInteger const& a, BigInteger const& b) { return (a - b).sign(); } 
    friend bool operator==(BigInteger const& a, BigInteger const& b) { return cmp(a , b) == 0; }
    friend bool operator!=(BigInteger const& a, BigInteger const& b) { return cmp(a , b) != 0; }
    friend bool operator<(BigInteger const& a, BigInteger const& b) { return cmp(a , b) < 0; }
    friend bool operator<=(BigInteger const& a, BigInteger const& b) { return cmp(a , b) <= 0; }
    friend bool operator>(BigInteger const& a, BigInteger const& b) { return cmp(a , b) > 0; }
    friend bool operator>=(BigInteger const& a, BigInteger const& b) { return cmp(a , b) >= 0; }

    void operator+=(BigInteger const& b) { add(b); }
    friend BigInteger operator+(BigInteger const& a, BigInteger const& b) {
        BigInteger res = a;
        res += b;
        return res;
    }
    void operator-=(BigInteger const& b) { add(two_complement(b)); }
    friend BigInteger operator-(BigInteger const& a, BigInteger const& b) {
        return a + two_complement(b);
    }
    void operator<<=(int shift_cnt) {
        int block_shift_cnt = shift_cnt / BITS_PER_BLOCK;
        int single_shift_cnt = shift_cnt % BITS_PER_BLOCK;
        for (int i = BLOCK_CNT - 1; i >= 0; i--) {
            blocks[i] = i >= block_shift_cnt ? blocks[i - block_shift_cnt] : 0u;
        }
        for (int i = 0; i < single_shift_cnt; i++) {
            shift_left();
        }
    }
    friend BigInteger operator<<(BigInteger const& a, int shift_cnt) {
        BigInteger res = a;
        res <<= shift_cnt;
        return res;
    }
    friend BigInteger operator*(BigInteger const& a, BigInteger const& b) {
        BigInteger result = 0;
        for (int i = 0; i < BLOCK_CNT; i++) {
            BigInteger sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += (uint64_t)a.blocks[j] * b.blocks[i - j];
            }
            result += sum << (i * BITS_PER_BLOCK);
        }
        return result;
    }
    void operator*=(BigInteger const& b) {
        *this = *this * b;
    }

    friend std::ostream& operator<<(std::ostream& os, BigInteger num) {
        if (num == 0) {
            return os << 0;
        }
        if (num < 0) {
            os << '-';
            two_complement(num);
        }
        std::vector<int> digits;
        while (num > 0) {
            auto div_mod = divmod(num, 10);
            auto& digit = div_mod.second;
            digits.push_back(digit.blocks[0]);
            num = div_mod.first;
        }
        reverse(digits.begin(), digits.end());
        for (auto digit : digits) {
            os << digit;
        }
        return os;
    }

private:
    static int const BITS_PER_BLOCK = 31;
    static int const BLOCK_CNT = (BITS + BITS_PER_BLOCK - 1u) / BITS_PER_BLOCK;
    using BlockType = uint32_t;
    using Blocks = std::array<BlockType, BLOCK_CNT>;
    static BlockType const BLOCK_BASE = 1u << BITS_PER_BLOCK;
    static BlockType const MASK_USED_BITS = (1u << BITS_PER_BLOCK) - 1u;
    // static BlockType const MASK_OVERFLOW = 1 << (BITS_PER_BLOCK + 1);
    
    static void two_complement(BigInteger& num) {
        for (auto& block : num.blocks) 
            block ^= MASK_USED_BITS;
        num += 1;
    }

    static BigInteger two_complement(BigInteger const& num) {
        auto res = num;
        two_complement(res);
        return res;
    }

    void add(BigInteger const& b) {
        BlockType carry = 0;
        for (int i = 0; i < BLOCK_CNT; i++) {
            blocks[i] += b.blocks[i] + carry;
            carry = blocks[i] >> BITS_PER_BLOCK;
            blocks[i] &= MASK_USED_BITS;
        }
    }

    void shift_right() {
        for (int i = 0; i < BLOCK_CNT; i++) {
            if (i) 
                blocks[i - 1] += (blocks[i] & 1) << (BITS_PER_BLOCK - 1);
            blocks[i] >>= 1;
        }
    }

    void shift_left() {
        for (int i = BLOCK_CNT - 1; i >= 0; i--) {
            blocks[i] <<= 1;
            blocks[i] &= MASK_USED_BITS;
            if (i) 
                blocks[i] += blocks[i - 1] >> (BITS_PER_BLOCK - 1);
        }
    }

    static std::pair<BigInteger, BigInteger> divmod(BigInteger a, BigInteger b) {
        // assuming both are positive
        int cnt = 0;
        while (b <= a) {
            b.shift_left();
            cnt++;
        }
        
        BigInteger result = 0;
        for (int i = 0; i < cnt; i++) {
            b.shift_right();
            result.shift_left();
            if (a >= b) {
                result.blocks[0] += 1u;
                a -= b;
            }
        }
        return {result, a};
    }

    Blocks blocks; // stored in 2-complement form
};

using ll = BigInteger<100>;

class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = std::vector<ll>(2 * n, 0);
	}

	void add(int idx, int value) {
		idx += n;
		data[idx] += value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = data[2 * idx] + data[2 * idx + 1];
		}
	}

	ll sum(int left, int right) { // interval [left, right)
		ll ret = 0;
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret += data[left++];
			if (right & 1) ret += data[--right];
			left >>= 1;
			right >>= 1;
		}
		return ret;
	}

private:
	int n;
	std::vector<ll> data;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    set<int> values;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        values.insert(v[i]);
        values.insert(v[i] - 1);
        values.insert(v[i] + 1);
    }
    vector<int> sorted(values.begin(), values.end());
    auto idx = [&sorted](int x) {
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    };
    SegmentTree cnts(sorted.size());
    SegmentTree sums(sorted.size());
    
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int j = idx(v[i]);
        auto s1 = sums.sum(0, j - 1);
        auto s2 = sums.sum(j + 2, sorted.size());
        auto c1 = cnts.sum(0, j - 1);
        auto c2 = cnts.sum(j + 2, sorted.size());
        res += (ll)v[i] * c1 - s1;
        res += (ll)v[i] * c2 - s2;

        sums.add(j, v[i]);
        cnts.add(j, 1);
    }
    cout << res << endl;
}