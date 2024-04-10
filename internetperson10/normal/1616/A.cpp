#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::map<int, int> nums;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            nums[std::abs(x)]++;
        }
        int ans = 0;
        for(auto p : nums) {
            if(p.first == 0) ans++;
            else ans += std::min(2, p.second);
        }
        std::cout << ans << '\n';
    }
}