#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
#include <tuple>
#include <queue>
#include <complex>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <functional>

using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    i64 T;
    std::cin >> n >> T;
    std::string s;
    std::cin >> s;
    
    T -= 1 << (s[n - 1] - 'a');
    T += 1 << (s[n - 2] - 'a');
    
    int cnt[26] {};
    
    for (int i = 0; i < n - 2; ++i) {
        T += 1 << (s[i] - 'a');
        ++cnt[s[i] - 'a'];
    }
    
    for (int i = 25; i >= 0; --i) {
        i64 t = std::min<i64>(std::max<i64>(0, T) >> (i + 1), cnt[i]);
        T -= t << (i + 1);
    }
    
    if (T == 0) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    
    return 0;
}