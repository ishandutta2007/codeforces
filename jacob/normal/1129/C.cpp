#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <array>

#include <cstdint>


#include <cassert>
#include <limits>

namespace number_theory {
namespace modular_arithmetic {

template<int modulus>
struct IntegerModulo {
	static constexpr int MOD = modulus;
	
	template<typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
	IntegerModulo(T value) {
		static_assert(MOD > 0, "modulus can't be <= 0");
		if (value >= MOD || value < 0) {
			value_ = static_cast<uint32_t>(value % MOD);
			if (value_ >= MOD) {
				// integer overflow
				value_ += MOD;
			}
		}
		else {
			value_ = static_cast<uint32_t>(value);
		}
	}
	IntegerModulo(const IntegerModulo&) = default;
	IntegerModulo(IntegerModulo&&) = default;
	IntegerModulo& operator=(const IntegerModulo&) = default;
	IntegerModulo& operator=(IntegerModulo&&) = default;
	

	template<typename T, class = typename std::enable_if<std::is_integral<T>::value>::type>
	explicit operator T() const {
		return static_cast<T>(value_);
	}

	friend IntegerModulo operator+(const IntegerModulo& left, const IntegerModulo& right) {
		uint32_t result = left.value_ + right.value_;
		if (result >= MOD) {
			result -= MOD;
		}
		return IntegerModulo(result, unchecked_t_());
	}
	IntegerModulo& operator+=(const IntegerModulo& other) {
		return (*this = *this + other);
	}
	
	
private:
	struct unchecked_t_ {};
	IntegerModulo(uint32_t value, unchecked_t_) {
		value_ = value;
	}
	uint32_t value_;
};


}  // namespace modular_arithmetic
}  // namespace number_theory
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


vector<int> prefix_function(const vector<char>& s) {
	int n = (int)s.size();
	vector<int> pi(n);
	for (int i = 1; i<n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

using IntMod = number_theory::modular_arithmetic::IntegerModulo<1000000007>;

constexpr array<int, 4> bad_arrays[] = {
	{1, 1, 1, 1},
	{0, 1, 1, 1},
	{1, 0, 1, 0},
	{1, 1, 0, 0},
};

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		int m;
		in >> m;
		vector<char> v;
		vector<IntMod> r;
		auto is_good = [&](int pos) {
			array<int, 4> vv;
			for (int i = 0; i < 4; ++i) {
				vv[i] = v[pos + i];
			}
			for (int i = 0; i < 4; ++i) {
				if (vv == bad_arrays[i])
					return false;
			}
			return true;
		};
		IntMod ans = 0;
		for (int i = 0; i < m; ++i) {
			int ch;
			in >> ch;
			v.push_back((char)ch);
			reverse(v.begin(), v.end());
			auto pi = prefix_function(v);
			int max_seen_before = *max_element(pi.begin(), pi.end());
			r.assign(i + 2, 0);
			r[0] = 1;
			for (int j = 0; j <= i; ++j) {
				for (int k = 1; k + j <= i + 1 && k <= 4; ++k) {
					if (k < 4 || is_good(j)) {
						r[j + k] += r[j];
					}
				}
			}
			for (int j = max_seen_before + 1; j <= i + 1; ++j) {
				ans += r[j];
			}
			out << (int)ans << endl;
			reverse(v.begin(), v.end());
		}
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}