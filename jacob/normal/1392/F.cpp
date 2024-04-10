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
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        vector<int64_t> h(n);
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            in >> h[i];
            sum += h[i];
        }
        int64_t l = 0, r = 1 + *max_element(h.begin(), h.end());
        while (r - l != 1) {
            int64_t m = (l + r) / 2;
            int64_t progSum = (2 * m + n - 1) * n / 2;
            if (progSum > sum) {
                r = m;
            }
            else {
                l = m;
            }
        }
        int64_t rem = sum - (2 * l + n - 1) * n / 2;
        for (int i = 0; i < n; ++i) {
            out << l + i + (i < rem ? 1 : 0) << " ";
        }
        out << endl;
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}