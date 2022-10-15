#include <iostream>
#include <vector>

using namespace std;

typedef std::pair<int, int> pii;

int MAX_LEN = 1000 * 1000 + 1;

int main() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto& p: v) {
        cin >> p.first >> p.second;
    }
    int res = 1000 * MAX_LEN;
    for (int H = 1; H <= 1000; ++H) {
        int len = 0;
        for (const auto& p: v) {
            int a = p.first;
            int b = p.second;
            if (a > b) {
                swap(a, b);
            }
            if (a > H) {
                len = MAX_LEN;
                break;
            }
            if (b <= H) {
                len += a;
            } else {
                len += b;
            }
        }
        if (len == MAX_LEN) continue;
        res = min(res, len * H);
    }
    std::cout << res << std::endl;
    return 0;
}